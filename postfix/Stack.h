#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace::std;
class Stack
{
public:
	Node* head;
	void push(char symbol) {
		Node* node = new Node(symbol);
		node->next = head;
		head = node;
	}
	char pop() {
		if (head == NULL) {
			cout << "Stack is empty";
			exit(0);
		}
		else {
			Node* tempN = head;
			char tempS = head->symbol;
			head = head->next;
			free(tempN);
			return tempS;
		}
	}
	void printStack() {
		Node* current = head;
		while (current != NULL) {
			cout << current->symbol;
			current = current->next;	
		}
	}
	Stack(){
		head = NULL;
	}
	};

