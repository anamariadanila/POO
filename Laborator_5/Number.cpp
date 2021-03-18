#include"Number.h"
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>

using namespace std;

int change_base_to_10(const char* value, int base) {

	int newNumber = 0, pow = 1;

	for (int i = 0; i < strlen(value); i++) {

		int number;

		if (value[i] == 'A') {
			number = 10;
		} else
			if (value[i] == 'B') {
				number = '11';
			} else
				if (value[i] == 'C') {
					number = 12;
				} else
					if (value[i] == 'D') {
						number = 13;
					} else
						if (value[i] == 'E') {
							number = 14;
						} else
							if (value[i] == 'F') {
								number = 15;
							}
							else
								number = value[i] - '0';
						newNumber = number * pow + newNumber;
						pow = pow * base;

	}

	return newNumber;
}

Number::Number(const char* value, int base)
{
	this->base = base;
	this->value = value;
}

Number::Number(const Number& x)
{
	this->value = x.value;
	this->base = x.base;
}

Number::Number(const Number&& x)
{
	this->value = x.value;
	this->base = x.base;
	//x.value = nullptr;
	//x.base = 0;
}

Number::~Number()
{
	delete value;
	value = nullptr;
	this->base = 0;
}

Number Number::operator+(Number number)
{
	
}

void Number::SwitchBase(int newBase)
{
	
}

void Number::Print()
{
	printf("%s\n, this->value");
}

int Number::GetDigitsCount()
{
	return strlen(value);
}

int Number::GetBase()
{
	return this->base;
}
