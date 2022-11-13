#include <iostream>

#include "beverage.h"

using namespace std;

int main()
{
	std::shared_ptr<Beverage> b1 = std::shared_ptr<Beverage>(new Espresso());
	cout << b1->GetDescription() << " $" << b1->Cost() << endl;

	std::shared_ptr<Beverage> b0 = std::shared_ptr<Beverage>(new DarkRoast());
	std::shared_ptr<Beverage> b2 = std::shared_ptr<Beverage>(new Whip(b0));
	cout << b2->GetDescription() << " $" << b2->Cost() << endl;

	std::shared_ptr<Beverage> b3 = std::shared_ptr<Beverage>(new HouseBlend());
	std::shared_ptr<Beverage> b4 = std::shared_ptr<Beverage>(new Soy(b3));
	cout << b4->GetDescription() << " $" << b4->Cost() << endl;
	return 0;
}