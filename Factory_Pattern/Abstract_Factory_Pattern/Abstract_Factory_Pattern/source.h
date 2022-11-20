#pragma once
#include <iostream>
using namespace std;

class Dough {

};

class ThinCrustDough : public Dough {
public:
	ThinCrustDough()
	{
		cout << "ThinCrustDough" << endl;
	}
};

class ThickCrustDough : public Dough {
public:
	ThickCrustDough()
	{
		cout << "ThickCrustDough" << endl;
	}

};

// =============================================

class Sauce {

};

class MarinaraSouce : public Sauce {
public:
	MarinaraSouce()
	{
		cout << "MarinaraSouce" << endl;
	}
};

class PlumTomatoSauce : public Sauce {
public:
	PlumTomatoSauce()
	{
		cout << "PlumTomatoSauce" << endl;
	}
};

// ==============================================

class Cheese {

};

class ReggianoCheese : public Cheese {
public:
	ReggianoCheese()
	{
		cout << "ReggianoCheese" << endl;
	}
};

class Spinach : public Cheese {
public:
	Spinach()
	{
		cout << "Spinach" << endl;
	}
};

// ==============================================

class Veggies {

};

class Garlic : public Veggies {
public:
	Garlic()
	{
		cout << "Garlic" << endl;
	}
};

class Onion : public Veggies {
public:
	Onion()
	{
		cout << "Onion" << endl;
	}
};
// ==============================================


class Pepperoni {

};

class SlicedPepperoni : public Pepperoni {
public:
	SlicedPepperoni()
	{
		cout << "SlicedPepperoni" << endl;
	}
};

class TestPepperoni : public Pepperoni {
public:
	TestPepperoni()
	{
		cout << "TestPepperoni" << endl;
	}
};

// ==============================================

class Clams {

};

class FreshClams : public Clams {
public:
	FreshClams()
	{
		cout << "FreshClams" << endl;
	}
};

class FrozenClams : public Clams {
public:
	FrozenClams()
	{
		cout << "FrozenClams" << endl;
	}
};