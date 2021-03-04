#include "Math.h"

int main() {
	cout << "Rezultat adunare: ";
	cout << Math::Add(2, 3) << endl;
	cout << "Rezultat adunare: ";
	cout << Math::Add(2, 3, 4) << endl; 
	cout << "Rezultat adunare: ";
	cout << Math::Add(2.5, 3.5) << endl;
	cout << "Rezultat adunare: ";
	cout << Math::Add(2.5, 3.5, 4.5) << endl;
	cout << "Rezultat inmultire: ";
	cout << Math::Mul(2, 3) << endl;
	cout << "Rezultat inmultire: ";
	cout << Math::Mul(2, 3, 4) << endl;
	cout << "Rezultat inmultire: ";
	cout << Math::Mul(2.5, 3.5) << endl;
	cout << "Rezultat inmultire: ";
	cout << Math::Mul(2.5, 3.5, 4.5) << endl;
	cout << "Rezultat adunare folosind parametri variadici: ";
	cout << Math::Add(3, 2, 3, 4) << endl;
	cout << "Rezultat concatenare: ";
	char* aux = Math::Add("buna", "ziua");
	cout << aux << endl;
	if (aux != nullptr) {
		free(aux);
	}
	return 0;


}