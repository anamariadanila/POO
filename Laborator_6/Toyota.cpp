#include"Toyota.h"

Toyota::Toyota()
{
	fuelConsumption = 10;
	fuelCapacity = 40;
	averageSpeed = new float[3]{ 30,20,15 };
	char nameCar[] = "Toyota";
	name = new char[strlen(nameCar) + 1];
	for (int i = 0; i < strlen(nameCar); i++) {
		name[i] = nameCar[i];
	}
	name[strlen(nameCar)] = 0;
}

Toyota::~Toyota()
{
	delete averageSpeed;
}

float Toyota::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Toyota::GetFuelConsumption()
{
	return this->fuelConsumption;
}

float Toyota::GetSpeed(Weather w)
{
	return this->averageSpeed[w];
}

char* Toyota::GetName()
{
	return this->name;
}

float Toyota::GetTime(float lenght, Weather w)
{
	float fuelUsed = (lenght / 100) * fuelConsumption;

	if (fuelUsed > fuelConsumption)
		return -1;
	return lenght / averageSpeed[w];
}
