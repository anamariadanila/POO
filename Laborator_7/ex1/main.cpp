#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

float operator"" _Kelvin(const char* x) {
    float value = atof(x);
    return  value - 273.15;

}

float operator"" _Fahrenheit(const char* x) {
    float value = atof(x);
    return((int)value - 32) / 1.8;

}




int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    cout << a << endl;
    cout << b;

    return 0;

}