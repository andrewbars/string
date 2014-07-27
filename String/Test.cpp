#include "String.h"
#include <iostream>
using namespace std;

void main()
{
	String s = "Test! It is a Test";
	String s2 = "Test";
	if (s.StartsWith(s2))
		cout << "working!";
}