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
	cout << s.PadRight(5, '!');
}