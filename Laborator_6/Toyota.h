#pragma once
#include "Car.h"

class Toyota :public Car {

public:
	Toyota();
	~Toyota();

	float GetFuelCapacity() override;
	float GetFuelConsumption() override;
	float GetSpeed(Weather w) override;
	virtual char* GetName() override;
	float GetTime(float lenght, Weather w) override;
};