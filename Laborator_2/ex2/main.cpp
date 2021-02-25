#include "Global.h"
#include <iostream>

using namespace std;

int main()
{
	Student s1, s2;
	s1.set_name("Danila Ana");
	s2.set_name("Ionescu Anca");

	s1.set_math(10);
	s2.set_math(8);

	s1.set_english(9);
	s2.set_english(9);

	s1.set_history(7);
	s2.set_history(9);

	s1.average_grade();
	s2.average_grade();

	cout << s1.average_grade() << "  " << s2.average_grade() << endl;
	cout << compare_name(s1, s2) << endl;
	cout << compare_math(s1, s2) << endl;
	cout << compare_english(s1, s2) << endl;
	cout << compare_history(s1, s2) << endl;
	cout << compare_average_grade(s1, s2);


	return 0;
}