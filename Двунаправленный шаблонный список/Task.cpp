#include <iostream>
#include "DoubleList.h"


void menu();

int main()
{
	List<int>* list = nullptr;

	auto it = List<int>::iterator(list);

	int chose = 0;
	do 
	{
		menu();

		std::cout << "\nEnter your chose: ";
		std::cin >> chose;

		switch (chose)
		{
		case 1: // заполнение
		{
			std::cout << "Enter count elements: ";
			int countElem;
			std::cin >> countElem;

			list = list->fillingList(countElem);
		}break;
		case 2: // печать
		{
			if (list != nullptr)
			{
				it = list->begin();

				while (it != nullptr)
				{
					std::cout << *it << " ";
					it++;
				}
			}
			else std::cout << "\nFilling the list!";
		}break;
		case 3: // обратная печать 
		{
			if (list != nullptr)
			{
				it = list->end();

				while (it != nullptr)
				{
					std::cout << *it << " ";
					it--;
				}
			}
			else std::cout << "\nFilling the list!";
		}break;
		case 4: //поиск элемента 
		{
			if (list != nullptr)
			{
				int findElem;
				std::cout << "\nEnter elem: ";
				std::cin >> findElem;

				if (list->isElemInList(findElem)) std::cout << "\nYes!";
				else std::cout << "\nNo!";
			}
			else std::cout << "\nFilling the list!";
		}break;
		case 5: // удаление элемента
		{
			if (list != nullptr)
			{
				int findElem;
				std::cout << "\nEnter elem: ";
				std::cin >> findElem;

				list->replaceElem(findElem);

				list = list->begin();
			}
			else std::cout << "\nFilling the list!";
		}break;
		case 6: //добавление элемента в голову
		{
			int addElem;
			std::cout << "\nEnter elem: ";
			std::cin >> addElem;

			list->addToHead(addElem);
		}break;
		case 7: // добавление после заданного 
		{
			if (list != nullptr)
			{
				int addElem;
				std::cout << "\nEnter add elem: ";
				std::cin >> addElem;

				int afterThis;
				std::cout << "\nEnter after what elem: ";
				std::cin >>afterThis;

				list->addAfterNode(afterThis, addElem);
			}
			else std::cout << "\nFilling the list!";
		}break;
		case 8: //добавление в конец
		{
			int addElem;
			std::cout << "\nEnter elem: ";
			std::cin >> addElem;

			list->addToTail(addElem);
		}break;
		case 9:// очистка списка
		{
			list->clearList();
			list = nullptr;
		}break;
		}
	} while (chose != 10);

	if (list != nullptr)
	{
		list->clearList();
		list = nullptr;
	}

	std::cin.ignore().get();
	return 0;
}

void menu()
{
	std::cout << "\n_______________________________________________";
	std::cout << "\n1)Filling list";
	std::cout << "\n2)Print";
	std::cout << "\n3)Reverse print";
	std::cout << "\n4)Is element in list";
	std::cout << "\n5)Replace element in list";
	std::cout << "\n6)Add to head";
	std::cout << "\n7)Add after node";
	std::cout << "\n8)Add to tail";
	std::cout << "\n9)Clear list";
	std::cout << "\n10)Exit";
	std::cout << "\n-----------------------------------------------";
}
