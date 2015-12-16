#include<iostream>
using namespace std;

#define STACK_SIZE 10

class StackError 
{
	int status_;
	
	public:
		StackError(int status) 
		{
			status_ = status;
		}
		
		int get_status() 
		{
			return status_;
		}
};

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
			return top == 0;
		}
		
		bool IsFull()
		{
			return top == STACK_SIZE;
		}
		
		void push(int x)
		{
			if(IsFull())
			{
				cout << "push() function called on a full stack!" << endl;
				throw StackError(2);
			}
			stack[top++] = x;
		}
		
		int pop()
		{
			if(IsEmpty())
			{
				cout << "pop() function called on an empty stack!" << endl;
				throw StackError(4);
			}
			return stack[--top];
		}
};

int main()
{
	Stack st;
	for(int count = 0; count < 10; count++)
	{
		st.push(count);
		
	}
	
	try 
	{
		st.push(11111);
	} catch(StackError ex) 
	{
		cout << "exception catched..." << endl;
		cout << ex.get_status() << endl;
	}
	cout << "this is next..." << endl;
	
	while(!st.IsEmpty()) 
	{
		cout << st.pop() << endl;
	}
	
	try {
		st.pop();
	} catch(StackError ex) 
	{
		cout << "exception catched..." << endl;
		cout << ex.get_status() << endl;
	}
	cout << "this is next..." << endl;
	return 0;
}
