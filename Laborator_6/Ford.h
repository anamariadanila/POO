#pragma once
#include"Car.h"

class Ford :public Car {
public:
	Ford();
	~Ford();

	float GetFuelCapacity() override;
	float GetFuelConsumption() override;
	float GetSpeed(Weather w) override;
	virtual char* GetName() override;
	float GetTime(float lenght, Weather w) override;
};