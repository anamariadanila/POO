#include"Dacia.h"

Dacia::Dacia()
{
	fuelConsumption = 15;
	fuelCapacity = 10;
	averageSpeed = new float[3]{ 30,25,20 };
	char nameCar[] = "Dacia";
	name = new char[strlen(nameCar) + 1];
	for (int i = 0; i < strlen(nameCar); i++) {
		name[i] = nameCar[i];
	}
	name[strlen(nameCar)] = 0;
}

Dacia::~Dacia()
{
	delete averageSpeed;
}

float Dacia::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Dacia::GetFuelConsumption()
{
	return this->fuelConsumption;
}

float Dacia::GetSpeed(Weather w)
{
	return this->averageSpeed[w];
}

char* Dacia::GetName()
{
	return this->name;
}

float Dacia::GetTime(float lenght, Weather w)
{
	float fuelUsed = (lenght / 100) * fuelConsumption;

	if (fuelUsed > fuelConsumption)
		return -1;
	return lenght / averageSpeed[w];
}
