#include "Student.h"

void Student::set_name(string n) {
	name = n;
}

string Student::get_name() {
	return name;
}



void Student::set_math(float x) {
	math = x;
}

float Student::get_math() {
	return math;
}


void Student::set_history(float x) {
	history = x;
}

float Student::get_history() {
	return history;
}

void Student::set_english(float x) {
	english = x;
}


float Student::get_english() {
	return english;
}

float Student::average_grade() {

	float avg = (math + english + history) / 3;
	return avg;
}