#include "pch.h"

int main()
{
	Dictionary dict;
	for (size_t i = 0; i < 15; i++)
	{
		dict.Add(i, std::to_string(i*i));
	}
	std::cout << "Print Dictionary:" <<std::endl;
	std::cout << "Key:\tValue:" << std::endl;
	dict.Print();
	std::cout << std::endl;
	std::cout << "Method dict.Search(5) returns: " << dict.Search(5);
	return 0;
}

