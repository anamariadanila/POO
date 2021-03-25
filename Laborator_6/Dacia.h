#pragma once
#include"Car.h"

class Dacia : public Car
{
public:
	Dacia();
	~Dacia();

	float GetFuelCapacity() override;
	float GetFuelConsumption() override;
	float GetSpeed(Weather w) override;
	virtual char* GetName() override;
	float GetTime(float lenght, Weather w) override;
};