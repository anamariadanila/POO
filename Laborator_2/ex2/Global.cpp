#include "Global.h"

int compare_name(Student s1, Student s2)
{
	if (s1.get_name() > s2.get_name()) {
		return 1;
	}
	else{
		if (s1.get_name() == s2.get_name()) {
			return 0;
		}
		else
			return -1;
	}
}

int compare_math(Student s1, Student s2)
{
	if (s1.get_math() > s2.get_math()) {
		return 1;
	}
	else {
		if (s1.get_math() == s2.get_math()) {
			return 0;
		}
		else
			return -1;
	}
}

int compare_english(Student s1, Student s2)
{
	if (s1.get_english() > s2.get_english()) {
		return 1;
	}
	else {
		if (s1.get_english() == s2.get_english()) {
			return 0;
		}
		else
			return -1;
	}
}

int compare_history(Student s1, Student s2)
{
	if (s1.get_history() > s2.get_history()) {
		return 1;
	}
	else {
		if (s1.get_history() == s2.get_history()) {
			return 0;
		}
		else
			return -1;
	}
}


int compare_average_grade(Student s1, Student s2)
{
	if (s1.average_grade() > s2.average_grade()) {
		return 1;
	}
	else {
		if (s1.average_grade() == s2.average_grade()) {
			return 0;
		}
		else
			return -1;
	}
}