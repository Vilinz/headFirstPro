#pragma once

class DisplayElement {
public:
	DisplayElement() = default;
	virtual ~DisplayElement() { };
	virtual void Display() = 0;
};