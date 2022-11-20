#pragma once
#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
	Pizza() = default;
	virtual ~Pizza() {}
	void Prepare()
	{
		std::cout << "Preparing " << name << std::endl;
		std::cout << "Tossing dough..." << std::endl;
		std::cout << "Adding sauce..." << std::endl;
		std::cout << "Adding toppings: ";
		for (auto& s : toppings) {
			std::cout << " " << s;
		}
		std::cout << std::endl;
	}

	void Bake()
	{
		std::cout << "Bake for 25 minutes at 350" << std::endl;
	}

	void Cut()
	{
		std::cout << "Cutting the pizza into diagonal slice" << std::endl;
	}

	void Box()
	{
		std::cout << "Place pizza in official PizzaStore box" << std::endl;
	}

	std::string GetName()
	{
		return name;
	}

protected:
	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;
};

class NYStyleCheesePizza : public Pizza {
public:
	NYStyleCheesePizza()
	{
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";

		toppings.push_back("Grated Reggiano Cheese");
	}
	virtual ~NYStyleCheesePizza() {}
};

class ChicagoStyleCheesePizza : public Pizza {
public:
	ChicagoStyleCheesePizza()
	{
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";

		toppings.push_back("Shredded Mozzarella Cheese");
	}

	virtual ~ChicagoStyleCheesePizza() {}

	void Cut()
	{
		std::cout << "Cutting the pizza into square slices" << std::endl;
	}
};
