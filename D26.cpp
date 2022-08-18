#include <iostream>
#include <string>

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int GetSize()
	{
		return Size;
	}

	T& operator[](const int index);

	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext!=nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current!=nullptr)
	{
		if (counter==index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}


}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index==0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;

		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
		
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;

		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;

	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size-1);
}

int main()
{
	setlocale(LC_ALL, "ru");

	List<int> lst;
	
	lst.push_back(7);
	lst.push_back(3);
	lst.push_back(11);
	lst.push_front(9);
	
	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;

	}

	std::cout << std::endl;

	lst.insert(4, 2);

	std::cout << std::endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
	
	std::cout << std::endl;

	lst.removeAt(1);

	std::cout << std::endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
	
	std::cout << std::endl;

	lst.pop_back();

	std::cout << std::endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
	



	return 0;
}
