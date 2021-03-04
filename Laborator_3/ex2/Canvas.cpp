#include"Canvas.h"
#include<iostream>
#include<math.h>

using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			this->matrix[i][j] = ' ';
		}
	}

}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{

	int i, j;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1) && (i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1)) {
				matrix[i][j] = ch;
			}
		}
	}


	
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{


	int i, j;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) {
				matrix[i][j] = ch;
			}
		}

		
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		this->matrix[top][i] = ch;

	for (int i = left; i <= right; i++)
		this->matrix[bottom][i] = ch;

	for (int i = top; i <= bottom; i++)
		this->matrix[i][right] = ch;

	for (int i = top; i <= bottom; i++)
		this->matrix[i][left] = ch;


}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++) {
		for (int j = left + 1; j < right; j++)
			this->matrix[i][j] = ch;
		
	}


}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	x = x1;
	y = y1;

	p = 2 * dy - dx;

	while (x < x2)
	{
		if (p >= 0)
		{
			matrix[x][y] = ch;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			matrix[x][y] = ch;
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void Canvas::Print()
{
	for (int i = 0; i <height; i++)
	{
		for (int j = 0; j <width; j++) {
			
			cout<<this->matrix[i][j];

		}
		cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}
