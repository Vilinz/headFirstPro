#pragma once
#include <iostream>
using namespace std;

// 定义鸭子叫行为
class QuackBehavior {
public:
	QuackBehavior() = default;
	virtual ~QuackBehavior() = default;

	virtual void DuckQuack() = 0;
};

// 通用叫行为
class Quack : public QuackBehavior {
public:
	Quack() = default;
	virtual ~Quack() { };
	void DuckQuack() override
	{
		cout << "Quack" << endl;
	}
};

// 静音
class MuteQuack : public QuackBehavior {
public:
	MuteQuack() = default;
	virtual ~MuteQuack() { };
	void DuckQuack() override
	{
		cout << "MuteQuack" << endl;
	}
};

// 吱吱吱声
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