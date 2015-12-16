#include<iostream>
using namespace std;

#define STACK_SIZE 10

class Stack
{
	int top;
	int stack[STACK_SIZE];
	
	public:
		
		Stack()
		{
			top = 0;
		}
		
		bool IsEmpty()
		{
			return (top == 0);
		}
		
		bool IsFull()
		{
			return (top == STACK_SIZE);
		}
		
		int push(int x)
		{
			if(IsFull())
			{
				cout << "push() function called on a full stack!" << endl;
				return -1; //for full stack
			}
			stack[top++] = x;
			return 0;
		}
		
		int pop()
		{
			if(IsEmpty())
			{
				cout << "pop() function called on an empty stack!" << endl;
				return -1; // for empty stack
			}
			return stack[--top];
		}
};

int main()
{
	Stack st;
	for(int count = 0; count < 50; count++)
	{
		if(st.push(count) == -1)
		{	
			cout << "Error in push!" << endl;
			break;
		}
	}
	return 0;
}
