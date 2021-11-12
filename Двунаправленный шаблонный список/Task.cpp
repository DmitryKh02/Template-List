#include <iostream>
#include "DoubleList.h"


int main()
{
	List<int>* PointerToHead = nullptr;
	List<int>* PointerToTail = nullptr;

	std::cout << "Enter count elements: ";
	int countElem;
	std::cin >> countElem;

	int value;
	while (countElem > 0)
	{
		std::cout << "\nEnter value: ";
		std::cin >> value;

		if (PointerToHead == nullptr)
		{
			PointerToHead->addToHead(PointerToHead, value);
			PointerToTail = PointerToHead;
		}
		else PointerToTail->addToTail(PointerToTail, value);

		countElem--;
	}

	PointerToHead->print(PointerToHead);
	std::cout << "\nReverse print: ";
	PointerToTail->reversePrint(PointerToTail);

	std::cout << "\nFind element in list: ";
	std::cin >> value;

	if (PointerToHead->isElemInList(PointerToHead, value)) std::cout << "\nYes, this element in list!";
	else std::cout << "No, this element is't in this list";


	PointerToHead->clearList(PointerToHead);

	std::cin.ignore().get();
	return 0;
}