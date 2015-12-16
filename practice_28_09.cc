#include<iostream>
using namespace std;



int main()
{
	int length = 0,str_counter, normal_brackets, curly_brackets;
	char ch,str[20];
	do
	{
		cin >> ch;
		str[length] = ch;
		length++;
	} while(cin);
	for(str_counter = 0; str_counter < length; str_counter++)
	{
		cout << str[str_counter];
	}
	for(normal_brackets = 0, curly_brackets = 0, str_counter = 0; str_counter < length; str_counter++)
	{
		if(str[str_counter] == '(')
		{
			
		}
		else if(str[str_counter] == ')')
		{
			
		}
		else if(str[str_counter] == '{')
		{
			
		}
		else if(str[str_counter] == '}')
		{
			
		}
	}
	return 0;
}
