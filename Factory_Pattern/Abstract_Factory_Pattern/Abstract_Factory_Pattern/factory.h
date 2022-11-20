#pragma once
#include <iostream>
#include <memory>

#include "source.h"

using namespace std;

class PizzaIngredientFactory {
public:
	PizzaIngredientFactory() = default;
	virtual ~PizzaIngredientFactory() {}
	virtual shared_ptr<Dough> CreateDough() = 0;
	virtual shared_ptr<Sauce> CreateSauce() = 0;
	virtual shared_ptr<Cheese> CreateCheese() = 0;
	virtual shared_ptr<Veggies> CreateViggies() = 0;
	virtual shared_ptr<Pepperoni> CreatePepperoni() = 0;
	virtual shared_ptr<Clams> CreateClams() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
	NYPizzaIngredientFactory()
	{
		cout << "NYPizzaIngredientFactory" << endl;
	}
	virtual ~NYPizzaIngredientFactory() {}

	shared_ptr<Dough> CreateDough() override
	{
		return make_shared<ThinCrustDough>();
	}

	shared_ptr<Sauce> CreateSauce() override
	{
		return make_shared<MarinaraSouce>();
	}

	shared_ptr<Cheese> CreateCheese() override
	{
		return make_shared<ReggianoCheese>();
	}

	shared_ptr<Veggies> CreateViggies() override
	{
		return make_shared<Garlic>();
	}

	shared_ptr<Pepperoni> CreatePepperoni() override
	{
		return make_shared<SlicedPepperoni>();
	}

	shared_ptr<Clams> CreateClams() override
	{
		return make_shared<FreshClams>();
	}
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
	ChicagoPizzaIngredientFactory()
	{
		cout << "ChicagoPizzaIngredientFactory" << endl;
	}
	virtual ~ChicagoPizzaIngredientFactory() {}

	shared_ptr<Dough> CreateDough() override
	{
		return make_shared<ThickCrustDough>();
	}

	shared_ptr<Sauce> CreateSauce() override
	{
		return make_shared<PlumTomatoSauce>();
	}

	shared_ptr<Cheese> CreateCheese() override
	{
		return make_shared<Spinach>();
	}

	shared_ptr<Veggies> CreateViggies() override
	{
		return make_shared<Onion>();
	}

	shared_ptr<Pepperoni> CreatePepperoni() override
	{
		return make_shared<TestPepperoni>();
	}

	shared_ptr<Clams> CreateClams() override
	{
		return make_shared<FrozenClams>();
	}
};