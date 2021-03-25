#pragma once
#include "Car.h"
#include<vector>

class Circuit {
	Weather weather;
	float lenght;

	std::vector<Car*> cars;
	std::vector<Car*> finished;
	std::vector<Car*> notFinished;

public:
	Circuit();
	~Circuit();

	void SetLength(float lenght);
	void SetWeather(Weather w);
	void AddCar( Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};