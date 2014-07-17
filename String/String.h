#pragma once
#include <cstring>
#include "Array.h"

class String
{
	Array<char> str;
	int length;
public:
	explicit String(int capacity = 80) : str(capacity > 10 ? capacity : 10), length(0) {};
	explicit String(char* origin);
	String(const String &that) :str(that.str), length(that.length){};
	String(char* origin, int capacity);
	String(String &that, int capacity);
};

