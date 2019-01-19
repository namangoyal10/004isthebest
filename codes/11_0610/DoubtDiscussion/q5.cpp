/*5. Take as input str, a string. Write a recursive function which returns a new string in
which all duplicate consecutive characters are separated by a ‘*’. E.g. for
“hello” return “hel*lo”. Print the value returned.*/

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

/*void fun(char str[], int n)
{
	if(n == 0) return;
	if(str[0] == str[1])
	{
		for(int i = n; i > 0; i--)
			str[i+1] = str[i];
		str[1] = '*';
		fun(str+2, n-1);
	}
	else fun(str+1, n-1);	
}*/

void Replace(char str[], char outstr[])
{
	if(str[0] == '\0') return;
	if(str[0] == str[1])
	{
		outstr[0] = str[0];
		outstr[1] = '*';
		outstr[2] = '\0';
		Replace(str+1, outstr+2);
	}
	else
	{
		outstr[0] = str[0];
		outstr[1] = '\0';
	    Replace(str+1, outstr+1);
	}
}

int main()
{
	char str[100];
	cin.getline(str, 20);
	char outstr[200];
	//fun(str, strlen(str));
	Replace(str, outstr);
	cout << outstr;
	getch();
	return 0;
}