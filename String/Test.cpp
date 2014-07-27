#include "String.h"
#include <iostream>
using namespace std;

void main()
{
	String s = "Test! It is a Test";
	String s2 = "Test";
	cout << s.LastIndexOf("Test");
	String s3 = s.DropRight(13);
	if (s3.StartsWith("Test!")&&s3.EndsWith("Test!"))
		cout << "Working!!";
}