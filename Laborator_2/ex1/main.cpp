#include <iostream>
#include "NumberList.h"

using namespace std;

int main() {

	NumberList lista;

	lista.Init();

	lista.Add(15);
	lista.Add(7);
	lista.Add(20);

	lista.Print();

	lista.Sort();

	lista.Print();

	return 0;

}