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

	bool Contains(const String &that, int startPos=0, int endPos=0) const;
	bool StartsWith(const String &that) const;
	bool EndsWith(const String &that) const;

	int IndexOf(char c) const;
	int IndexOf(const String &that) const;
	int LastIndexOf(char c) const;
	int LastIndexOf(const String &that) const;
	int IndexOfAny(const String &that) const;

	String Take(int num);
	String Drop(int num);
	String TakeRight(int num);
	String DropRight(int num);
};

