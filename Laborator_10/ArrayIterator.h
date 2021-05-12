#pragma once
template<class T>
class ArrayIterator
{
private:
	int Current;
	T** element;
public:

	ArrayIterator() : Current(-1)
	{};
	ArrayIterator(int index, T** p) :Current(index), element(p)
	{}

	ArrayIterator(int index, T& p) : Current(index)
	{
		element = &(&p);
	}

	ArrayIterator& operator ++ () {
		element++;
		Current++;
		return (*this);
	}
	ArrayIterator& operator -- () {
		if (Current == 0) {

		}
		element--;
		Current--;
		return (*this);
	}
	bool operator= (ArrayIterator<T>& other) {
		Current = other.GetCurrent();
		element = other.GetElement();
	};

	int GetCurrent() {
		return Current;
	}

	bool operator!=(ArrayIterator<T>& other) {
		return element != other.GetElement();
	}
	T** GetElement() {
		return element;
	}

};