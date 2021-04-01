#pragma once
#include<iostream>
using namespace std;
#define DOUBLE_SIZE\
	if( newLength+1 >= currentLenght)\
	{\
		int size = currentLenght * 2; \
		T* temp = new T[size]; \
		memcpy(temp, arrayObj, currentLenght * sizeof(T)); \
		currentLenght = size; \
		delete[] arrayObj; \
		arrayObj = temp;\
	}
template <class T>
class Vector {

private:

	T* arrayObj;
	int newLenght;
	int currentLenght;

public:

	Vector() {
		this->newLenght = 0;
		this->currentLenght = 1;
		arrayObj = new T[this->currentLenght];
	}

	void Push(const T& element); //add an element at the end of the vector

	int Pop(); //return the last element from the vector

	void Remove(int position); //removes an element from a specific index in the vector

	void Insert(const T& element, int position); //insert an element at a specific index

	void Sort(bool(*function_callback)(T obj1, T obj2)); //sort all elements in the vector ==> use a callback function to provide a way to compare two elements. If the callback function is not present (nullptr), operator< is used.

	const T& Get(int position); //returns a constant reference to an object from the vector

	void Set(const T& element, int position); //set an object to a specific index --> that index must be already used by another object

	int Count(); //returns the number of elements in the vector

	int FirstIndexOf(const T& element, bool(*function_callback)(T obj1, T obj2));

	void Print();



	void doubleSize() {
	
		int size = this->currentLenght * 2;
		T* temp = new T[size];
			for (int i = 0; i < this->currentLenght; i++) {
				temp[i] = arrayObj[i];
		}

		    delete[] arrayObj;
			arrayObj = temp;
		}
	
	

}; //https://www.whitman.edu/mathematics/c++_online/section04.03.html


template<class T>
 void Vector<T>::Push(const T& element)
{
	doubleSize();
	this->arrayObj[this->currentLenght] = element;
	this-> currentLenght++;
}


template<class T>
int Vector<T>::Pop()
{
	this->currentLenght--;
	return this->arrayObj[this->currentLenght];
}



template<class T>
 void Vector<T>::Remove(int position)
{
	for (int i = position; i < this->currentLenght - 1; i++) {
		this->arrayObj[i] = this->arrayObj[i + 1];
	}
	this->currentLenght--;
}

template<class T>
 void Vector<T>::Insert(const T& element, int position)
{
	doubleSize();
	for (int i = this->currentLenght - 1; i >= position; i--) {
		this->arrayObj[i + 1] = this->arrayObj[i];
	}
	this->arrayObj[position] = element;
	this->currentLenght++;
}

template<class T>
 void Vector<T>::Sort(bool(*function_callback)(T obj1, T obj2))
{
	if (function_callback == nullptr) {
		for (T i = 0; i < this->currentLenght; i++) {
			for (T j = 0; j < this->currentLenght; j++) {
				if (arrayObj[i] < arrayObj[j]) {

					T temp = arrayObj[i];
					arrayObj[i] = arrayObj[j];
					arrayObj[j] = temp;

				}
			}
		}
	}
	else {
		for (T i = 0; i < this->currentLenght; i++) {
			for (T j = 0; j < this->currentLenght; j++) {
				if (function_callback(arrayObj[i], arrayObj[j])) {

					T temp = arrayObj[i];
					arrayObj[i] = arrayObj[j];
					arrayObj[j] = temp;

				}
			}
		}

	}
}

template<class T>
 const T& Vector<T>::Get(int position)
{
	// TODO: insert return statement here
	return this->arrayObj[position - 1];
}

template<class T>
 void Vector<T>::Set(const T& element, int position)
{
	if (position > this->currentLenght - 1) {
		cout << "Bad position";
	}
	else {
		this->arrayObj[position] = element;
	}
}

template<class T>
 int Vector<T>::Count()
{
	return this->currentLenght;
}

template<class T>
 int Vector<T>::FirstIndexOf(const T& element, bool(*function_callback)(T obj1, T obj2))
{
	if (function_callback == nullptr) {
		for (T i = 0; i < this->currentLenght; i++) {
			T temp = arrayObj[i];
			if (temp == element) {
				return i;
			}
		}
	}

	else {
		for (T i = 0; i < this->currentLenght; i++) {
			T temp = arrayObj[i];
			if (function_callback(temp, element)) {
				return i;
			}
		}
	}
}

template<class T>
 void Vector<T>::Print()
{
	for (T i = 0; i < this->currentLenght; i++) {
		cout << this->arrayObj[i];
	}
	cout << endl;
}

template<class T>
int compare(T obj1, T obj2)
{
	if (obj1 > obj2) {
		return 1;
	}
	return -1;
}

template<class T>
int equal(int obj1, int obj2) {
	if (obj1 == obj2) {
		return 1;
	}
	else return 0;
}
