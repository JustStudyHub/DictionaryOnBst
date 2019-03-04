#include "pch.h"
#include "Dictionary.h"

Dictionary::Node::Node()
{
	this->lchild = nullptr;
	this->rchild = nullptr;
}

Dictionary::Node::Node(int key, std::string value)
{
	this->lchild = nullptr;
	this->rchild = nullptr;
	this->key = key;
	this->value = value;
}

Dictionary::Dictionary()
{
	this->start = nullptr;
	this->count = 0;
}

Dictionary::~Dictionary()
{
	if (start == nullptr)
	{
		return;
	}
	std::stack<Node*> s;
	Node temp;
	if (start == nullptr)
		return;
	s.push(start);
	while (s.size() != 0)
	{
		temp = *s.top();
		delete s.top();
		s.pop();
		if (temp.lchild != nullptr)
			s.push(temp.lchild);
		if (temp.rchild != nullptr)
			s.push(temp.rchild);
	}
}

void Dictionary::Add(int key, std::string value)
{
	if (start == nullptr)
	{
		start = new Node(key, value);
		count = 1;
		return;
	}
	Node* temp = this->start;
	while (true)
	{
		if (temp->key > key)
		{
			if (temp->lchild == nullptr)
			{
				temp->lchild = new Node(key, value);
				++count;
				break;
			}
			temp = temp->lchild;
		}
		else
		{
			if (temp->rchild == nullptr)
			{
				temp->rchild = new Node(key, value);
				++count;
				break;
			}
			temp = temp->rchild;
		}
	}
}

std::string Dictionary::Search(int key)
{
	std::string res = "";
	std::stack<Node*> s;
	Node *temp;
	if (start == nullptr)
		return res;
	s.push(start);
	temp = start;
	while (true)
	{
		if (temp->key > key)
		{
			temp = temp->lchild;
		}
		else
		{
			temp = temp->rchild;
		}
		if (temp->key == key)
		{
			res = temp->value;
			break;
		}
		if (temp->lchild == nullptr && temp->rchild == nullptr)
		{
			break;
		}
	}
	return res;
}

void Dictionary::Print()
{
	std::stack<Node*> s;
	Node *temp;
	if (start == nullptr)
		return;
	s.push(start);
	while (s.size() != 0)
	{
		std::cout << s.top()->key << "\t" << s.top()->value << std::endl;
		temp = s.top();
		s.pop();
		if (temp->lchild != nullptr)
			s.push(temp->lchild);
		if (temp->rchild != nullptr)
			s.push(temp->rchild);
	}
}
