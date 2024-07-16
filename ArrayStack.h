#include<iostream>
using namespace std;
struct ArrayStack
{
	int *S;
	int capacity;
	int top;
	ArrayStack(int cap = 100)
	{
		S = new int[cap];
		capacity = cap;
		top = -1;
	}
	bool ArrayStack::isEmpty() {
		return (top < 0);
	}
	int ArrayStack::Size() {
		return (top + 1);
	}
	int ArrayStack::Top() {
		return S[top];
	}
	void ArrayStack::Push(int x) {
		if (Size() == capacity) {
			cout << "Stack Full !!! " << endl;
		}
		else
		{
			S[++top] = x;
		}
	}
	int ArrayStack::Pop() {
		return S[top--];
	}
};
