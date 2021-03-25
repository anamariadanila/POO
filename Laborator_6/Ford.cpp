#include"Ford.h"

Ford::Ford()
{
	fuelConsumption = 7;
	fuelCapacity = 90;
	averageSpeed = new float[3]{ 50,30,20 };
	char nameCar[] = "Ford";
	name = new char[strlen(nameCar) + 1];
	for (int i = 0; i < strlen(nameCar); i++) {
		name[i] = nameCar[i];
	}
	name[strlen(nameCar)] = 0;
}

Ford::~Ford()
{
	delete averageSpeed;
}

float Ford::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Ford::GetFuelConsumption()
{
	return this->fuelConsumption;
}

float Ford::GetSpeed(Weather w)
{
	return this->averageSpeed[w];
}

char* Ford::GetName()
{
	return this->name;
}

float Ford::GetTime(float lenght, Weather w)
{
	float fuelUsed = (lenght / 100) * fuelConsumption;

	if (fuelUsed > fuelConsumption)
		return -1;
	return lenght / averageSpeed[w];
}
