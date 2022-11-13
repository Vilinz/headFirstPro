#pragma once

#include <string>
#include <memory>

// 基类
class Beverage {
public:
	Beverage() = default;
	virtual ~Beverage() = default;

	virtual std::string GetDescription()
	{
		return description;
	}

	virtual double Cost() = 0;

protected:
	std::string description = "Unknow Beverage";
};

// 装饰者类
class CondimentDecorator : public Beverage {
public:
	virtual std::string GetDescription() = 0;
};

// 饮料
class Espresso : public Beverage {
public:
	Espresso()
	{
		description = "Espresso";
	}

	virtual ~Espresso() = default;

	double Cost() override
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend()
	{
		description = "HouseBlend";
	}

	virtual ~HouseBlend() = default;

	double Cost() override
	{
		return 0.89;
	}
};

class DarkRoast : public Beverage {
public:
	DarkRoast()
	{
		description = "DarkRoast";
	}

	virtual ~DarkRoast() = default;

	double Cost() override
	{
		return 2.89;
	}
};

class Decaf : public Beverage {
public:
	Decaf()
	{
		description = "Decaf";
	}

	virtual ~Decaf() = default;

	double Cost() override
	{
		return 0.69;
	}
};

// 具体装饰者
class Mocha : public CondimentDecorator {
public:
	Mocha(std::shared_ptr<Beverage> ptr)
	{
		this->beverage = ptr;
	}

	virtual ~Mocha() = default;

	std::string GetDescription() override
	{
		return beverage->GetDescription() + ", Mocha";
	}

	double Cost() override
	{
		return 0.20 + beverage->Cost();
	}

private:
	std::shared_ptr<Beverage> beverage;
};

class Whip : public CondimentDecorator {
public:
	Whip(std::shared_ptr<Beverage> ptr)
	{
		this->beverage = ptr;
	}

	virtual ~Whip() = default;

	std::string GetDescription() override
	{
		return beverage->GetDescription() + ", Whip";
	}

	double Cost() override
	{
		return 0.30 + beverage->Cost();
	}

private:
	std::shared_ptr<Beverage> beverage;
};

class Soy : public CondimentDecorator {
public:
	Soy(std::shared_ptr<Beverage> ptr)
	{
		this->beverage = ptr;
	}

	virtual ~Soy() = default;

	std::string GetDescription() override
	{
		return beverage->GetDescription() + ", Soy";
	}

	double Cost() override
	{
		return 0.40 + beverage->Cost();
	}

private:
	std::shared_ptr<Beverage> beverage;
};