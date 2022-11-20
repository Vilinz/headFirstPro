#pragma once
#include <memory>
#include <string>

#include "productor.h"

class PizzaStore {
public:
	PizzaStore() = default;
	virtual ~PizzaStore() {}
	std::shared_ptr<Pizza> OrderPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = CreatePizza(type);
		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();
		
		return pizza;
	}

protected:
	virtual std::shared_ptr<Pizza> CreatePizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore {
public:
	NYPizzaStore() = default;
	virtual ~NYPizzaStore() {}
protected:
	std::shared_ptr<Pizza> CreatePizza(std::string type) override
	{
		if (type == "Cheese") {
			return std::make_shared<NYStyleCheesePizza>();
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
	std::shared_ptr<Pizza> CreatePizza(std::string type) override
	{
		if (type == "Cheese") {
			return std::make_shared<ChicagoStyleCheesePizza>();
		} else { // add kind here
			return nullptr;
		}
	}
};