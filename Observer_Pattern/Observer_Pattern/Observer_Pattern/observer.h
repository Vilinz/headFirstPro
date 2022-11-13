#pragma once

class Observer {
public:
	Observer() = default;
	virtual ~Observer() { }
	virtual void Update(float temp, float humidity, float pressure) = 0;
};