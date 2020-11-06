#pragma once
//#include <iostream>
#include <string>
//using namespace::std;
class Node
{
public:
	char symbol;
	int priority;
	Node* next;

	Node(char symbol) {
		this->symbol = symbol;
		this->priority = getPriority(symbol);
		this->next = NULL;
	}

	int getPriority(char symbol) {
		switch (symbol)
		{
		case '(':
			return 0;
		case ')':
			return 1;
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		case '^':
				return 4;
		case '#':
			return -2;
			default:
				return -1;
				break;
		}
	}
};

