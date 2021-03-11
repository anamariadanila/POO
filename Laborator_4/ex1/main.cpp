#include "Sort.h"

int main() {
	Sort list(10, 20, 5);
	list.InsertSort(false);
	list.Print();

	Sort list1("51,32,12,76,445");
	list1.BubbleSort(false);
	list1.Print();

	Sort list2{ new int[8]{5,2,1,6,4,7,8,3},8 };
	list2.QuickSort(false);
	list2.Print();
	printf("Element from index ");
	printf("%d \n", list2.GetElementFromIndex(6));

	Sort list3(10, 100, 10);
	list3.QuickSort(false);
	list3.Print();

	Sort list4("10,40,100,5,70");
	list4.InsertSort(false);
	list4.Print();
	printf("Count Elements ");
	printf("%d \n", list4.GetElementsCount());
	  

	int array[6] = { 3,1,5,2,9,3 };
	Sort list5(array, 6);
	list5.InsertSort(false);
	list5.Print();

}