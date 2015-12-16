#include<iostream>
#include<string>
using namespace std;


int main()
{
	string line;
	char ch;
	getline(cin, line);
	while(cin)
	{
		cout << '|' << line << '|' << endl;
		getline(cin,line);
	}
	return 0;
}
