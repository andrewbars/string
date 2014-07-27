#pragma once

#include "Array.h"

class String
{
	Array<char> str;
	int length;
public:
	explicit String(int capacity = 80) : str(capacity > 10 ? capacity : 10), length(0) {};
	String(char* origin);
	String(const String &that) :str(that.str), length(that.length){};
	String(char* origin, int capacity);
	String(String &that, int capacity);

	int Length() const;
	int Capacity();

	operator char*();

	String& operator =(const String &that);
	String& operator =(char* string);
	String& operator +=(char* string);
	String& operator +=(const String &that);

	bool operator >(const String &that);
	bool operator >=(const String &that);
	bool operator <(const String &that);
	bool operator <=(const String &that);
	bool operator ==(const String &that);
	bool operator !=(const String &that);

	String operator +(const String &that);

	bool Contains(const String &that, int startPos=0, int endPos=0);
	bool StartsWith(const String &that);
	bool EndsWith(const String &that);

};

