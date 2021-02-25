#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string name;
	float math;
	float history;
	float english;

public:
	    void set_name(string n);
		string get_name();
	

		void set_math(float x);
		float get_math();

	

		void set_history(float x);
		float get_history();
    

		void set_english(float x);
		float get_english();
	

	    float average_grade();
};