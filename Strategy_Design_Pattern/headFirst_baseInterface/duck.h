#pragma once
#include <memory>
#include "bahavior.h"


class Duck {
public:
	Duck() = default;
	virtual ~Duck() = default;

	virtual void Display() = 0;

	void PerformFly()
	{
		flyBehavior->DuckFly();
	}

	void PerformQuack()
	{
		quackBehavior->DuckQuack();
	}

	void SetFlyBehavior(shared_ptr<FlyBehavior> ptr)
	{
		flyBehavior = ptr;
	}

	void SetQuackBehavior(shared_ptr<QuackBehavior> ptr)
	{
		quackBehavior = ptr;
	}

	void Swim()
	{
		cout << "All ducks float, even decoys" << endl;
	}

protected:
	shared_ptr<FlyBehavior> flyBehavior;
	shared_ptr<QuackBehavior> quackBehavior;
};

// ÊµÀý
class MallarDuck : public Duck {
public:
	MallarDuck()
	{
		flyBehavior = make_shared<FlyWithWings>();
		quackBehavior = make_shared<Quack>();
	};

	~MallarDuck()
	{
		cout << "~MallarDuck" << endl;
	}

	void Display() override
	{
		cout << "I`m a real Mallard duck" << endl;
	}
};