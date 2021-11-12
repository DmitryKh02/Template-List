#pragma once

template <class T>
class List
{
protected:
	T data;
	List* next;
	List* prev;
	static List* head;
	static List* tail;

protected:
	void init(T elem);
	bool isEmpty();

	void deleteHead();
	void deleteAfterNode(List* place);
	void deleteTail();
	
	List* FindPlaceInList(T elem);
public:
	List(T elem, List* _prev = nullptr, List* _next = nullptr);
	~List();

	List* fillingList(int countElem);
	void addToHead(T value);
	void addAfterNode(T place, T value);
	void addToTail(T value);

	
	void clearList();

	bool isElemInList(T elem);
	
	void replaceElem(T elem);

	void print();
	void reversePrint();

	List* begin();
	List* end();

	class iterator 
	{
	protected:
		List* pointer;
	public:
		iterator(const iterator& other) : pointer(other->pointer) {};
		iterator(List<T>* node) : pointer(node) {};

		iterator& operator=(const iterator& other) { if (pointer != other.pointer) pointer = other.pointer; return *this; };
		T& operator*() const { return pointer->data; };

		bool operator==(const iterator& other) const { return pointer == other.pointer; };
		bool operator!=(const iterator& other) const { return pointer != other.pointer; };

		iterator& operator++() { return pointer->next; }
		iterator& operator++(int) { iterator* dop = this; pointer = pointer->next; return *dop; }
		iterator& operator--() { return pointer->prev; }
		iterator& operator--(int) { iterator* dop = this; pointer = pointer->prev; return *dop; }

		friend void swapIterators(iterator& first, iterator& second) { iterator dop = second; second = first; first = dop; };
	};
};

template <class T>
List<T>* List<T>::head = nullptr;
template <class T>
List<T>* List<T>::tail = nullptr;

template<class T>
List<T>::List(T elem, List* _prev, List* _next)
{
	data = elem;
	prev = _prev;
	next = _next;
}

template<class T>
List<T>::~List()
{
	prev = nullptr;
	next = nullptr;
}

template<class T>
void List<T>::init(T elem)
{
	List* dop = new List(elem);

	head = dop;
	tail = dop;
}

template<class T>
bool List<T>::isEmpty()
{
	return head == nullptr;
}



template<class T>
List<T>* List<T>::fillingList(int countElem)
{
	clearList();
	T value;

	while (countElem > 0)
	{
		std::cout << "\nEnter value: ";
		std::cin >> value;

		if (head == nullptr) init(value);
		else addToTail(value);

		countElem--;
	}
	return head;
}
template<class T>
void List<T>::addToHead(T value)
{
	if (isEmpty()) init(value);
	{
		List* add = new List(value,nullptr,head);

		add->next->prev = add;
		head = add;
		add = nullptr;
	}
}

template<class T>
void List<T>::addAfterNode(T place, T value)
{
	if (isElemInList(place)&&!isEmpty())
	{
		List* pos = FindPlaceInList(place);

		if (pos == tail) addToTail(value);
		else 
		{
			List* dop = new List(value, pos, pos->next);
			pos->next = dop;
			dop->next->prev = dop;

			dop = nullptr;
		}
	}
}
	


template<class T>
void List<T>::addToTail(T value)
{
	if (isEmpty()) init(value);
	{
		List* add = new List(value,tail,nullptr);

		tail->next = add;
		tail = add;
		add = nullptr;
	}
}



template<class T>
void List<T>::deleteHead()
{
	if (!isEmpty())
	{
		List* del = head;

		if (head->next != nullptr) head = head->next;
		else head = nullptr;

		delete del;
		del = nullptr;
	}
}

template<class T>
void List<T>::deleteTail()
{
	if (!isEmpty())
	{
		List* del = tail;

		if (tail->prev != nullptr)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete del;
		del = nullptr;
	}
}

template<class T>
void List<T>::deleteAfterNode(List* place)
{
	if (place->next != nullptr)
	{
		List* del = place->next;

		place->next = del->next;

		if(del->next!=nullptr) del->next->prev = place;

		delete del;
		del = nullptr;
	}
}


template<class T>
void List<T>::clearList()
{
	if (!isEmpty())
	{
		while (head->next != nullptr)
			deleteTail();
		deleteHead();
	}
}



template<class T>
bool List<T>::isElemInList(T elem)
{
	bool find = false;

	if (!isEmpty())
	{
		List* pointer = head;

		while ((pointer != nullptr) && (!find))
		{
			if (pointer->data == elem) find = true;
			else pointer = pointer->next;
		}
	}

	return find;
}

template<class T>
List<T>* List<T>::FindPlaceInList(T elem)
{
	List* pointer = head;

	if (!isEmpty())
	{
		while (pointer->data != elem && pointer!=nullptr)
			pointer = pointer->next;
	}	
	
	return pointer;
}

template<class T>
void List<T>::replaceElem(T elem) 
{
	if (!isEmpty()&&isElemInList(elem))
	{
		List* pointer = head;
		while (pointer->data != elem)
			pointer = pointer->next;

		if (pointer == head) deleteHead();
		else if (pointer == tail) deleteTail();
		else deleteAfterNode(pointer->prev);
	}
}



template<class T>
void List<T>::print()
{
	if (!isEmpty())
	{
		List* pointer = head;

		while (pointer != nullptr)
		{
			std::cout << "\nElem is " << pointer->data;
			pointer = pointer->next;
		}
	}
}

template<class T>
void List<T>::reversePrint()
{
	if (!isEmpty())
	{
		List* pointer = tail;

		while (pointer != nullptr)
		{
			std::cout << "\nElem is " << pointer->data;
			pointer = pointer->prev;
		}
	}
}


template<class T>
List<T>* List<T>::begin()
{
	return head;
}

template<class T>
List<T>* List<T>::end()
{
	return tail;
}

