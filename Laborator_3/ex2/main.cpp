#include "Canvas.h"
#include<iostream>

int main() {

	Canvas canvas(20, 20);
	canvas.DrawCircle(9, 9, 8, '*');
	//canvas.Print();
	//canvas.Clear();
	canvas.FillCircle(9, 9, 8, '%');
	canvas.Print();
	canvas.Clear();
	canvas.DrawRect(5,5,14,14, '*');
	//canvas.Print();
	//canvas.Clear();
	canvas.FillRect(5, 5, 14, 14, '#');
	canvas.Print();
	canvas.Clear();
	canvas.DrawLine(3, 3, 10, 10, '@');
	canvas.Print();
	canvas.Clear();

	return 0;
}