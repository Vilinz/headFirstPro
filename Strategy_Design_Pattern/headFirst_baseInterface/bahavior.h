#pragma once
#include <iostream>
using namespace std;

// ����Ѽ�ӽ���Ϊ
class QuackBehavior {
public:
	QuackBehavior() = default;
	virtual ~QuackBehavior() = default;

	virtual void DuckQuack() = 0;
};

// ͨ�ý���Ϊ
class Quack : public QuackBehavior {
public:
	Quack() = default;
	virtual ~Quack() { };
	void DuckQuack() override
	{
		cout << "Quack" << endl;
	}
};

// ����
class MuteQuack : public QuackBehavior {
public:
	MuteQuack() = default;
	virtual ~MuteQuack() { };
	void DuckQuack() override
	{
		cout << "MuteQuack" << endl;
	}
};

// ֨֨֨��
class Squeak : public QuackBehavior {
public:
	Squeak() = default;
	virtual ~Squeak() { };
	void DuckQuack() override
	{
		cout << "Squeak" << endl;
	}
};

// ==========================================================
class FlyBehavior {
public:
	FlyBehavior() = default;
	virtual ~FlyBehavior() = default;

	virtual void DuckFly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
	FlyWithWings() = default;
	virtual ~FlyWithWings() { };

	void DuckFly() override
	{
		cout << "FlyWithWings" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	FlyNoWay() = default;
	virtual ~FlyNoWay() { };

	void DuckFly() override
	{
		cout << "FlyNoWay" << endl;
	}
};

// =======================================================