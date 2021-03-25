#include "Circuit.h"
using namespace std;

Circuit::Circuit() 
{
}

Circuit::~Circuit()
{
}

void Circuit::SetLength(float lenght)
{ 
	this->lenght = lenght;
}

void Circuit::SetWeather(Weather w)
{
	this->weather = w;
}

void Circuit::AddCar( Car* car)
{
	cars.push_back((Car*)car);
}

void Circuit::Race()
{
	
	int numberOfCars = cars.size();
	bool ok;

	for (int i = 0; i < numberOfCars; i++) {
		if (cars[i]->GetTime(this->lenght, this->weather) > 0) {
			finished.push_back(cars[i]);
		}
		else {
			notFinished.push_back(cars[i]);
		}
	}

	do {
		ok = true;
		int finishNumber = finished.size();
		for (int i = 0; i < finishNumber - 1; i++) {
			float car1 = finished[i]->GetTime(lenght, weather);
			float car2 = finished[i + 1]->GetTime(lenght, weather);
			if (car1 > car2) {
				Car* intermediate = finished[i];
				finished[i] = finished[i + 1];
				finished[i + 1] = intermediate;
				ok = false;
			}
		}


	} while (!ok);
}

void Circuit::ShowFinalRanks()
{
	cout << "No\tName\tTime\n";
	int numberFinished = finished.size();
	
	for (int i = 0; i < numberFinished; i++) {
		cout << i + 1 << ".\t" << finished[i]->GetName() << "\t" << finished[i]->GetTime(lenght, weather) << "\n";
	}

}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "No\tName\n";
	int numberNotFinished = notFinished.size();

	for (int i = 0; i < numberNotFinished; i++) {
		cout << i + 1 << ".\t" << notFinished[i]->GetName() << "\n";
	}
}
