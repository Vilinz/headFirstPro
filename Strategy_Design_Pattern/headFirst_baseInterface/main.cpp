#include <iostream>

#include "duck.h"
using namespace std;

int main()
{
	shared_ptr<Duck> duck = make_shared<MallarDuck>();
	duck->PerformFly();
	duck->PerformQuack();
	duck->Display();
	return 0;
}