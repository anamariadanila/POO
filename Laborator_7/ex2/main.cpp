#include "Header.h"
#include <iostream>



int main()
{
	Vector<int> vec;

	vec.Push(7);
	vec.Push(3);
	vec.Push(2);
	vec.Push(15);
	
	vec.Print();

	vec.Insert(11, 4);

	vec.Sort(nullptr);

	printf("Array - ascending order ");
	vec.Print();
	printf("\n\n");

	printf("Object at second index ");
	printf("%d \n\n", vec.Get(2));

	printf("Number of elements: ");
	printf("%d \n\n", vec.Count());

	vec.Push(26);
	printf("First index of 26 ");
	printf("%d \n", vec.FirstIndexOf(26, nullptr));

	
	printf("Set at index 6 number 17 \n");
	vec.Set(17, 6);
	vec.Print();
	printf("\n\n");

	printf("Remove element at index 3 \n");
	vec.Remove(3);
	vec.Print();

	printf("\n\n Take out ");
	printf("%d  ", vec.Pop());

	printf("\n\n");
	printf("Array ");
	vec.Print();

}

