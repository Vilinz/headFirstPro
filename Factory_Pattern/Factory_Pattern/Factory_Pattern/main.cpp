#include <iostream>
#include "creator.h"

int main()
{
	std::shared_ptr<PizzaStore> store(new NYPizzaStore());
	std::shared_ptr<PizzaStore> store1(new ChicagoPizzaStore());

	std::shared_ptr<Pizza> p1 = store->OrderPizza("Cheese");
	if (p1)
		std::cout << "Vilin ordered a " << p1->GetName() << std::endl;

	std::shared_ptr<Pizza> p2 = store1->OrderPizza("Cheese");
	if (p2)
		std::cout << "Vilin ordered a " << p2->GetName() << std::endl;

	return 0;
}