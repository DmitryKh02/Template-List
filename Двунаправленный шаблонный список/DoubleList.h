#pragma once

template <class T>
struct List
{
private:
	T data;
	List* next;
	List* prev;
public:
	void init(List*& head,T elem);
	bool isEmpty(List* head);
	
	void addToHead(List*& head, T value);
	void addAfterNode(List*& place, T value);
	void addToTail(List*& tail, T value);

	void deleteHead(List*& head);
	void deleteAfterNode(List*& place);
	void deleteTail(List*& tail);

	bool isElemInList(List* head, T elem);
	List* FindPlaceInList(List* head, T elem);

	void clearList(List*& head);

	void print(List* head);
	void reversePrint(List* tail);
};

template<class T>
void inline List<T>::init(List*& head,T elem)
{
	*head = new List;
	head->next = nullptr;
	head->prev = nullptr;
	head->data = elem;
}

template<class T>
inline bool List<T>::isEmpty(List* head)
{
	return head == nullptr;
}



template<class T>
inline void List<T>::addToHead(List*& head, T value)
{
	List* add = new List;

	add->data = value;
	add->next = head;
	if(head!=nullptr) head->prev = add;
	add->prev = nullptr;
	head = add;
	add = nullptr;
}

template<class T>
inline void List<T>::addAfterNode(List*& place, T value)
{
	List* add = new List;

	add->data = value;

	add->next = place->next;
	place->next->prev = add;

	place->next = add;
	add->prev = place;
	add = nullptr;
	delete add;
}

template<class T>
inline void List<T>::addToTail(List*& tail, T value)
{
	List* add = new List;

	add->data = value;
	add->prev = tail;
	tail->next = add;
	add->next = nullptr;
	tail = add;
	add = nullptr;
}



template<class T>
inline void List<T>::deleteHead(List*& head)
{
	if (!isEmpty(head))
	{
		List* del = head;

		if (head->nex != nullptr)
		{
			head = head->next;
			head->prev = nullptr;
		}

		head->prev = nullptr;
		del->next = nullptr;

		delete del;
		del = nullptr;
	}
}

template<class T>
inline void List<T>::deleteAfterNode(List*& place)
{
	if (place->next != nullptr)
	{
		List* del = place->next;

		place->next = del->next;
		if(del->next!=nullptr) del->next->prev = place;

		del->next = nullptr;
		del->prev= nullptr;
		delete del;
		del = nullptr;
	}
}

template<class T>
inline void List<T>::deleteTail(List*& tail)
{
	if (tail != nullptr)
	{
		List* del = tail;
		if (tail->prev != nullptr)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		del->prev = nullptr;

		delete del;
		del = nullptr;
	}
}



template<class T>
inline bool List<T>::isElemInList(List* head, T elem)
{
	bool find = false;

	while ((head->next != nullptr) && (!find))
	{
		if (head->data == elem) find = true;
		else head = head->next;
	}
	return find;
}

template<class T>
inline List<T>* List<T>::FindPlaceInList(List* head, T elem)
{
	while (head != nullptr || head->data != elem)
		head = head->next;

	List* place = head;

	return place;
}

template<class T>
inline void List<T>::clearList(List*& head)
{
	if (!isEmpty(head))
	{
		while (head->next != nullptr)
		{
			deleteAfterNode(head);
		}
		delete head;
		head = nullptr;
	}
}



template<class T>
inline void List<T>::print(List* head)
{
	while (head != nullptr)
	{
		std::cout << "\nElem is " << head->data;
		head = head->next;
	}
}

template<class T>
inline void List<T>::reversePrint(List* tail)
{
	while (tail != nullptr)
	{
		std::cout << "\nElem is " << tail->data;
		tail = tail->prev;
	}
}
