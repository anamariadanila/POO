#include "Sort.h"

Sort::Sort(int minValue, int maxValue, int numberOfElements)
{
	srand((unsigned)time(0));
	this->numberOfElementsList = numberOfElements;
	this->list = new int[numberOfElements];
	int dif = maxValue - minValue;
	int i = 0;
	while (i < this->numberOfElementsList) {
		this->list[i] = (rand() % (dif-1)) + minValue;
		i++;
	}
}

Sort::Sort() :list(new int[10] {1, 2, 3, 4, 5})
{
	this->numberOfElementsList = 10;
}


Sort::Sort(int * vector, int numberOfElementsVector)
{
	this->numberOfElementsList = numberOfElementsVector;
	this->list = vector;
	
}

Sort::Sort(int numberOfElements, ...)
{
	list = new int[numberOfElements];
	this->numberOfElementsList = numberOfElements;
	va_list args;
	va_start(args, numberOfElements);
	int i=0;
	while (i < numberOfElements) {
		this->list[i] = va_arg(args, int);
		i++;
	}
	va_end(args);

}

Sort::Sort(const char* stringList)
{
	this->list = new int[strlen(stringList)];
	this->list[0] = 0;
	int count = 0;
	int number = 0;

	for (int i = 0; i < strlen(stringList); i++) {
		if (stringList[i] != ',') {

			number = number * 10 + (stringList[i] - '0');
			this->list[count] = number;
			
		}
		else {
			count++;
			number = 0;
		}
	}
	this->numberOfElementsList = count + 1;

	
}

void Sort::InsertSort(bool ascendent)
{
	int key, j;
	for (int i = 1; i < this->numberOfElementsList; i++) {
		key = this->list[i];
		j = i;
		if (ascendent == true) {
			while (j > 0 && this->list[j - 1] > key) {
				this->list[j] = this->list[j - 1];
				j--;
			}
			this->list[j] = key;
		}
		else {
			while (j > 0 && this->list[j - 1] < key) {
				this->list[j] = this->list[j - 1];
				j--;
			}
			this->list[j] = key;

		}
	}
}
void quickSort(int vector[], int left, int right)
{
	if (left < right)
	{

		int avg = (left + right) / 2;
		int aux = vector[left];
		vector[left] = vector[avg];
		vector[avg] = aux;
		int i = left, j = right, d = 0;
		while (i < j)
		{
			if (vector[i] > vector[j])
			{
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(vector, left, i - 1);
		quickSort(vector, i + 1, right);
	}
}

void Sort::QuickSort(bool ascendent)
{
	
	quickSort(this->list, 0, this->numberOfElementsList - 1);

}

void Sort::BubbleSort(bool ascendent)
{

	for (int i = 0; i <this->numberOfElementsList; i++)
		for (int j = 0; j < this->numberOfElementsList - i - 1; j++)

			if (ascendent == false) {

				if (this->list[j] > this->list[j + 1])
				{
					int aux = this->list[j];
					this->list[j] = this->list[j + 1];
					this->list[j + 1] = aux;
				}
			}

			else
			{
				if (this->list[j] < this->list[j + 1]) {

					int aux = this->list[j];
					this->list[j] = this->list[j + 1];
					this->list[j + 1] = aux;

				}
			}
}



void Sort::Print()
{
	for (int i = 0; i < this->numberOfElementsList; i++)
		printf("%d ", this->list[i]);
	printf("\n");
}



int Sort::GetElementsCount()
{
	return this->numberOfElementsList;
}



int Sort::GetElementFromIndex(int index)
{
	if (index < 0 && index > this->numberOfElementsList) {
		return -1;
	}
	return this->list[index];
}
