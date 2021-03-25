#pragma once
#include "Car.h"

class Mercedes : public Car {
	
public:
	Mercedes();
	~Mercedes();

	float GetFuelCapacity() override;
	float GetFuelConsumption() override;
	float GetSpeed(Weather w) override;
	virtual char* GetName() override;
	float GetTime(float lenght, Weather w) override;
};