#pragma once
#include"ArrayIterator.h"
#include"Compare.h"
#include<iostream>
#include"Exceptions.h"
template<class T>
class Array
{
private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	// Lista nu e alocata, Capacity si Size = 0
	Array() : Capacity(0), Size(0)
	{};

	// destructor
	~Array() {
		for (int i = 0; i < Size; i++) {
			delete List[i];
		}
		delete[] List;
	};

	// Lista e alocata cu 'capacity' elemente
	Array(int capacity) : Capacity(capacity), Size(0)
	{
		List = new T * [Capacity + 1];
	};

	// constructor de copiere
	Array(const Array<T>& otherArray) : Capacity(otherArray.GetCapacity()), Size(otherArray.GetSize())
	{
		List = new T * [Capacity + 1];
		for (int i = 0; i < this->Size; i++) {
			List[i] = new T();
			(*(List[i])) = otherArray[i];
		}
	};


	// arunca exceptie daca index este out of range
	T& operator[] (int index) const {

		if (index < 0 || index >= Size) {
			OutOfBoundsException err;
			throw err;
		}
		return *(List[index]);
	}

	void print() {
		for (int i = 0; i < Size; i++) {
			std::cout << *(List[i]) << " ";
		}
	}


	// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& operator+=(const T& newElem) {

		if (Size == Capacity) {
			NoCapacity err;
			throw err;
		}

		List[this->Size] = new T();
		*(List[this->Size]) = newElem;
		this->Size++;
		return (*this);
	};

	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const T& newElem) {
		if (index < 0 || index >= Size) {
			OutOfBoundsException err;
			throw err;
		}
		if (Size == Capacity) {
			NoCapacity err;
			throw err;
		}

		List[this->Size] = new T();
		this->Size++;

		for (int i = this->Size - 1; i >= index + 1; i--) {
			*(List[i]) = *(List[i - 1]);
		}
		*(List[index]) = newElem;
		return (*this);
	}

	// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		int currIndex = index;
		for (int element = 0; element < otherArray.GetSize(); element++, currIndex++) {
			this->Insert(currIndex, otherArray[element]);
		}
		return (*this);
	}


	// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index) {
		if (index < 0 || index >= Size) {
			OutOfBoundsException err;
			throw err;
		}
		for (int i = index; i < Size - 1; i++) {
			List[i] = List[i + 1];
		}
		delete List[Size - 1];
		Size--;
	}



	bool operator=(const Array<T>& otherArray) {
		for (int i = 0; i < Size; i++) {
			delete List[i];
		}
		delete[] List;

		List = new T * [Capacity + 1];
		for (int i = 0; i < this->Size; i++) {
			List[i] = new T();
			(*(List[i])) = otherArray[i];
		}
		return true;

	}


	// sorteaza folosind comparatia intre elementele din T
	void Sort() {
		bool sortat = false;
		do {
			sortat = true;
			for (int i = 0; i < Size - 1; i++) {
				if (*(List[i]) < *(List[i + 1])) {
					T* aux;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
					sortat = false;
				}
			}
		} while (!sortat);
	}


	void Sort(int(*compare)(const T&, const T&)) {
		bool sortat = false;
		do {
			sortat = true;
			for (int i = 0; i < Size - 1; i++) {
				if (compare(*(List[i]), *(List[i + 1])) <= 0) {
					T* aux;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
					sortat = false;
				}
			}
		} while (!sortat);
	}

	void Sort(Compare* comparator) {
		bool sortat = false;
		do {
			sortat = true;
			for (int i = 0; i < Size - 1; i++) {
				if (comparator->CompareElements((List[i]), (List[i + 1])) <= 0) {
					T* aux;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
					sortat = false;
				}
			}
		} while (!sortat);

	}// sorteaza folosind un obiect de comparatie



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) {
		int stanga = 0, dreapta = Size - 1;
		while (stanga <= dreapta) {
			int mijloc = (stanga + dreapta) / 2;
			if (*(List[mijloc]) == elem) {
				return mijloc;
			}
			if (*(List[mijloc]) > elem) {
				dreapta = mijloc - 1;
			}
			else {
				stanga = mijloc - 1;
			}
		}
		return -1;
	}// cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int stanga = 0, dreapta = Size - 1;
		while (stanga <= dreapta) {
			int mijloc = (stanga + dreapta) / 2;
			if (compare(*(List[mijloc]), elem) == 0) {
				return mijloc;
			}
			if (compare(*(List[mijloc]), elem) > 0) {
				dreapta = mijloc - 1;
			}
			else {
				stanga = mijloc - 1;
			}
		}
		return -1;
	}//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator) {
		int stanga = 0, dreapta = Size - 1;
		while (stanga <= dreapta) {
			int mijloc = (stanga + dreapta) / 2;
			if (comparator->CompareElements((List[mijloc]), &elem) == 0) {
				return mijloc;
			}
			if (comparator->CompareElements((List[mijloc]), &elem) > 0) {
				dreapta = mijloc - 1;
			}
			else {
				stanga = mijloc - 1;
			}
		}
		return -1;

	}//  cauta un element folosind binary search si un comparator



	int Find(const T& elem) {
		for (int i = 0; i < Size - 1; i++) {
			if (*(List[i]) == elem) {
				return i;
			}
		}
		return -1;
	}// cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size - 1; i++) {
			if (compare(*(List[i]), elem) == 0) {
				return i;
			}
		}
		return -1;
	}//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i < Size - 1; i++) {
			if ((comparator->CompareElements(List[i]), &elem) == 0) {
				return i;
			}
		}
		return -1;
	}//  cauta un element folosind un comparator



	int GetSize() const {
		return Size;
	}

	int GetCapacity() const {
		return Capacity;
	}



	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> begin(0, &List[0]);
		return begin;
	};

	ArrayIterator<T> GetEndIterator() {
		ArrayIterator<T> end(Size - 1, &List[Size - 1]);
		return end;
	};

};