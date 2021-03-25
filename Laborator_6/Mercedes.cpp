#include "Mercedes.h"

Mercedes::Mercedes()
{
	fuelConsumption = 10;
	fuelCapacity = 50;
	averageSpeed = new float[3]{ 40,30,20 };
	char nameCar[] = "Mercedes";
	name = new char[strlen(nameCar) + 1];
	for (int i = 0; i < strlen(nameCar); i++) {
		name[i] = nameCar[i];
	}
	name[strlen(nameCar)] = 0;
}

Mercedes::~Mercedes()
{
	delete averageSpeed;
}

float Mercedes::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Mercedes::GetFuelConsumption()
{
	return this->fuelConsumption;
}

float Mercedes::GetSpeed(Weather w)
{
	return this->averageSpeed[w];
}

char* Mercedes::GetName()
{
	return this->name;
}

float Mercedes::GetTime(float lenght, Weather w)
{
	float fuelUsed = (lenght / 100) * fuelConsumption;

	if (fuelUsed > fuelConsumption)
		return -1;
	return lenght / averageSpeed[w];
}
