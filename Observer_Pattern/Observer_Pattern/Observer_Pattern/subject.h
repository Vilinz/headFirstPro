#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "observer.h"
#include "displayElement.h"

class Subject {
public:
	Subject() = default;
	virtual ~Subject() = default;
	virtual void RegisterObserver(std::shared_ptr<Observer> ptr) = 0;
	virtual void RemoveObserver(std::shared_ptr<Observer> ptr) = 0;
	virtual void NotifyObserver() = 0;
};

class WeatherData : public Subject {
public:
	WeatherData() = default;
	virtual ~WeatherData()
	{
		std::cout << "~WeatherData" << std::endl;
	}

	void RegisterObserver(std::shared_ptr<Observer> ptr) override
	{
		observers.push_back(ptr);
	}

	void RemoveObserver(std::shared_ptr<Observer> ptr) override
	{
		for (auto iter = observers.begin(); iter != observers.end(); iter++) {
			auto it = (*iter).lock();
			if (it == ptr) {
				observers.erase(iter);
				break;
			}
		}
	}

	void NotifyObserver() override
	{
		for (auto& it : observers) {
			auto iter = it.lock();
			if (iter) {
				iter->Update(temperature, humidity, pressure);
			}
		}

		observers.erase(std::remove_if(observers.begin(), observers.end(),
			[](const std::weak_ptr<Observer>& o)
			{
				return o.expired();
			}), observers.end());
	}

	void MeasurementsChanged()
	{
		NotifyObserver();
	}

	void SetMeasurements(float temp, float humidity, float pressure)
	{
		this->temperature = temp;
		this->humidity = humidity;
		this->pressure = pressure;
		MeasurementsChanged();
	}

private:
	float temperature;
	float humidity;
	float pressure;
	std::vector<std::weak_ptr<Observer>> observers;
};

// =======================================

class CurrentConditionsDisplay : public Observer, DisplayElement {
public:
	CurrentConditionsDisplay(std::shared_ptr<Subject> weatherData)
	{
		this->weatherData = weatherData;
		// 本来打算在这里订阅，但是构造函数拿不到指能指针，继承enable_shared_from_this指能指针是在构造函数之后生成的
	}

	virtual ~CurrentConditionsDisplay()
	{
		std::cout << "~CurrentConditionsDisplay" << std::endl;
	}

	void Update(float temp, float humidity, float pressure) override
	{
		this->temperature = temp;
		this->humidity = humidity;
		Display();
	}

	void Display() override
	{
		std::cout << "CurrentConditionsDisplay: temperature: " << temperature << ", humidity: " << humidity << std::endl;
	}
private:
	float temperature;
	float humidity;
	std::shared_ptr<Subject> weatherData;
};