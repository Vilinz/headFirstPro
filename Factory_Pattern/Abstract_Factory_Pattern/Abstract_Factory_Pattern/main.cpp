#include <iostream>

#include "pizza.h"

using namespace std;

int main()
{
	shared_ptr<PizzaStore> store = make_shared<NYPizzaStore>();
	shared_ptr<PizzaStore> store1 = make_shared<ChicagoPizzaStore>();;

	shared_ptr<Pizza> p1 = store->OrderPizza("Cheese");
	if (p1)
		cout << "Vilin ordered a " << p1->GetName() << endl;

	shared_ptr<Pizza> p2 = store1->OrderPizza("Cheese");
	if (p2)
		cout << "Vilin ordered a " << p2->GetName() << endl;

	return 0;
}