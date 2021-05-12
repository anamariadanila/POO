#include<iostream>
#include"Compare.h"
#include"Array.h"

int main() {
	Array<int> a(1);

	try {
		a += 3;
		a += 3;
	}
	catch (OutOfBoundsException & err) {
		std::cout << err.what();
	}
	catch (NoCapacity & err) {
		std::cout << err.what();
	}


	return 0;
}