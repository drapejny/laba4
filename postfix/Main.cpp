#include "Node.h"
#include "Stack.h"
#include <string>
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
void main() {
	string infixString = "";
	cin >> infixString;
	string postfixString = "";
	Stack* stack = new Stack();
	stack->push('#');
	for (int i = 0; i < infixString.length(); i++) {
		char c = infixString[i];
		int priority = getPriority(c);
		if (priority == -1) {
			postfixString += c;
		}
		else
			if (priority == 1) {
				char current = stack->pop();
				while (current != '(') {
					postfixString += current;
					current = stack->pop();
				}
			}
			else
				if (priority == 0 || priority > stack->head->priority) {
					stack->push(c);
				}
				else {
					while (priority <= stack->head->priority)
						postfixString += stack->pop();
					stack->push(c);
				}
		
	}
	if (stack->head->symbol != '#') {
		while (stack->head->symbol != '#')
			postfixString += stack->pop();
	}
	cout << postfixString;
}
		

