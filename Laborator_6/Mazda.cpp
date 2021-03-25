#include "Mazda.h"

Mazda::Mazda()
{
	fuelConsumption = 13;
	fuelCapacity = 60;
	averageSpeed = new float[3]{ 45,30,25 };
	char nameCar[] = "Mazda";
	name = new char[strlen(nameCar) + 1];
	for (int i = 0; i < strlen(nameCar); i++) {
		name[i] = nameCar[i];
	}
	name[strlen(nameCar)] = 0;
}

Mazda::~Mazda()
{
	delete averageSpeed;
}

float Mazda::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Mazda::GetFuelConsumption()
{
	return this->fuelConsumption;
}

float Mazda::GetSpeed(Weather w)
{
	return this->averageSpeed[w];
}

char* Mazda::GetName()
{
	return this->name;
}

float Mazda::GetTime(float lenght, Weather w)
{
	float fuelUsed = (lenght / 100) * fuelConsumption;

	if (fuelUsed > fuelConsumption)
		return -1;
	return lenght / averageSpeed[w];
}
