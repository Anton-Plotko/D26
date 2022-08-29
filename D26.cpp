#include <iostream>
#include <string>
#include "List.h"


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
