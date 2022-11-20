#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "source.h"
#include "factory.h"

using namespace std;

class Pizza {
public:
	Pizza()
	{
		cout << "Pizza" << endl;
	}

	virtual ~Pizza() {}

	virtual void Prepare() = 0;
		
	void Bake()
	{
		cout << "Bake for 25 minutes at 350" << endl;
	}

	void Cut()
	{
		cout << "Cutting the pizza into diagonal slices" << endl;
	}

	void Box()
	{
		cout << "Place pizza in official PizzaStore box" << endl;
	}

	void SetName(string n)
	{
		name = n;
	}

	string GetName()
	{
		return name;
	}

protected:
	string name;
	shared_ptr<Dough> dough;
	shared_ptr<Sauce> sauce;
	shared_ptr<Veggies> veggies;
	shared_ptr<Cheese> cheese;
	shared_ptr<Pepperoni> pepperoni;
	shared_ptr<Clams> clam;
};

class CheesePizza : public Pizza {
public:
	CheesePizza(shared_ptr<PizzaIngredientFactory> factory)
	{
		ingredientFactory = factory;
		cout << "CheesePizza" << endl;
	}

	virtual ~CheesePizza(){}

	void Prepare() override
	{
		cout << "Preparing " << name << endl;
		dough = ingredientFactory->CreateDough();
		sauce = ingredientFactory->CreateSauce();
		cheese = ingredientFactory->CreateCheese();
	}

private:
	shared_ptr<PizzaIngredientFactory> ingredientFactory;
};

class ClamPizza : public Pizza {
public:
	ClamPizza(shared_ptr<PizzaIngredientFactory> factory)
	{
		ingredientFactory = factory;
		cout << "ClamPizza" << endl;
	}

	virtual ~ClamPizza() {}

	void Prepare() override
	{
		cout << "Preparing " << name << endl;
		dough = ingredientFactory->CreateDough();
		sauce = ingredientFactory->CreateSauce();
		cheese = ingredientFactory->CreateCheese();
		clam = ingredientFactory->CreateClams();
	}

private:
	shared_ptr<PizzaIngredientFactory> ingredientFactory;
};

class PizzaStore {
public:
	PizzaStore() = default;
	virtual ~PizzaStore() {}
	shared_ptr<Pizza> OrderPizza(string type)
	{
		shared_ptr<Pizza> pizza = CreatePizza(type);
		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();

		return pizza;
	}

protected:
	virtual shared_ptr<Pizza> CreatePizza(string type) = 0;
};

class NYPizzaStore : public PizzaStore {
public:
	NYPizzaStore() = default;
	virtual ~NYPizzaStore() {}
protected:
	shared_ptr<Pizza> CreatePizza(string type) override
	{
		shared_ptr<PizzaIngredientFactory> ingredientFactory = make_shared<NYPizzaIngredientFactory>();
		if (type == "Cheese") {
			shared_ptr<Pizza> pizza;
			pizza = make_shared<CheesePizza>(ingredientFactory);
			pizza->SetName("New York Style Cheese Pizza");
			return pizza;
		} else { // add kind here
			return nullptr;
		}
	}
};

class ChicagoPizzaStore : public PizzaStore {
public:
	ChicagoPizzaStore() = default;
	virtual ~ChicagoPizzaStore() {}
protected:
	shared_ptr<Pizza> CreatePizza(string type) override
	{
		shared_ptr<PizzaIngredientFactory> ingredientFactory = make_shared<ChicagoPizzaIngredientFactory>();
		if (type == "Cheese") {
			shared_ptr<Pizza> pizza;
			pizza = make_shared<CheesePizza>(ingredientFactory);
			pizza->SetName("Chicago Style Cheese Pizza");
			return pizza;
		}
		else { // add kind here
			return nullptr;
		}
	}
};
