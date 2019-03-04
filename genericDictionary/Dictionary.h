#pragma once
#include "pch.h"
class Dictionary
{
private:
	struct Node
	{
		Node();
		Node(int key, std::string value);

		int key;
		std::string value;
		Node* lchild;
		Node* rchild;
	};

	Node* start;
	int count;

public:
	Dictionary();
	~Dictionary();
	void Add(int key, std::string value);
	std::string Search(int key);
	void Print();
};

