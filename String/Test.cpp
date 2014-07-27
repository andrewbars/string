#include "String.h"
#include <iostream>
using namespace std;

void main()
{
	String s = "Test! It is Test.";
	String s2 = "Test";
	cout << s << endl;
	cout << s.Replace(s2, "Working") << endl;
	cout << s.PadLeft(5) << endl;
	cout << s.PadRight(5, '!') << endl;
	String s3 = "This is another test";
	Array<String> splitStr = s3.Split(' ');
	for (int i = 0; i < splitStr.Length(); i++)
	{
		cout << splitStr[i] << endl;
	}

	String s4 = "   Normalization     test   ";
	cout << s4 << '!'<<endl;
	cout << s4.Normalize() << '!' << endl;
}