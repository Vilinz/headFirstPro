#include <iostream>

#include "subject.h"

int main()
{

	// ��������
	std::shared_ptr<WeatherData> weather = std::make_shared<WeatherData>();

	// �۲���
	std::shared_ptr<CurrentConditionsDisplay> observer = std::make_shared<CurrentConditionsDisplay>(weather);
	// CurrentConditionsDisplay dis = CurrentConditionsDisplay(weather);

	weather->RegisterObserver(observer);

	weather->SetMeasurements(90, 20, 29.0f);

	std::cout << "weatherData count: " << weather.use_count() << std::endl;
	std::cout << "observer count: " << observer.use_count() << std::endl;

	return 0;
}