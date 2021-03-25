#pragma once
#include "Car.h"

class Mazda :public Car {

public:
	Mazda();
	~Mazda();

	float GetFuelCapacity() override;
	float GetFuelConsumption() override;
	float GetSpeed(Weather w) override;
	virtual char* GetName() override;
	float GetTime(float lenght, Weather w) override;
};