#include "String.h"
#include <cstring>


String::String(char *origin) :str(origin?strlen(origin):80)
{
	if (origin)
	{
		length = strlen(origin);
		for (int i = 0; i < length; i++)
			str[i] = origin[i];
	}
	else
		length = 0;
}

String::String(char* origin, int capacity) :str(capacity)
{
	if (origin)
	{
		length = (strlen(origin)+1) < capacity ? (strlen(origin)+1) : capacity;
		for (int i = 0; i < length; i++)
			str[i] = origin[i];
	}
	else
		length = 0;
}

String::String(String &that, int capacity) :str(capacity)
{
	length = capacity>that.length ? that.length : capacity;
	for (int i = 0; i < length; i++)
	{
		str[i] = that.str[i];
	}
}

int String::Length() const
{
	return length;
}

int String::Capacity()
{
	return str.Length();
}

String::operator char*()
{
	char* string = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		string[i] = str[i];
	}
	string[length] = '\0';
	return string;
}

String& String::operator=(const String &that)
{
	if (str.Length() < that.length)
	{
		str.Resize(that.length);
	}
	length = that.length;
	for (int i = 0; i < length; i++)
	{
		str[i] = that.str[i];
	}
	return *this;
}

String& String::operator=(char* string)
{
	if (string&&strlen(string))
	{
		int stringLength = strlen(string);
		if (str.Length() < stringLength)
		{
			str.Resize(stringLength);
		}
		length = stringLength;
		for (int i = 0; i < length; i++)
		{
			str[i] = string[i];
		}
	}
	return *this;
}

String& String::operator+=(const String &that)
{
	if (str.Length() < length + that.length)
		str.Resize(length + that.length + 1);
	for (int i = 0; i < that.length; i++)
	{
		str[i + length] = that.str[i];
	}
	length += that.length;
	return *this;
}

String& String::operator+=(char* string)
{
	if (string&&strlen(string))
	{
		int stringLength = strlen(string);
		if (str.Length() < length + stringLength)
			str.Resize(length + stringLength);
		for (int i = 0; i < stringLength; i++)
		{
			str[i + length] = string[i];
		}
		length += stringLength;
	}
	return *this;
}

bool String::operator>(const String &that)
{
	return strcmp((char*)this, (char*)((String)that))>0;
}

bool String::operator>=(const String &that)
{
	return strcmp((char*)this, (char*)((String)that))>=0;
}

bool String::operator<(const String &that)
{
	return !(*this>that);
}

bool String::operator<=(const String &that)
{
	return !(*this>=that);
}

bool String::operator ==(const String &that)
{
	return strcmp((char*)this, (char*)((String)that))==0;
}

bool String::operator !=(const String &that)
{
	return !(*this==that);
}

String String::operator+(const String &that)
{
	String tmp(*this, length + that.length);
	tmp += that;
	return tmp;
}


bool String::Contains(const String &that, int startPos, int endPos)
{
	if (!endPos)
		endPos = length;
	for (int i = startPos; i <= endPos - that.Length(); i++)
	{
		if (str[i] == that.str[0])
		{
			int k = 0;
			while (i + k < length&&k < that.length&&str[i + k] == that.str[k])
				k++;
			if (k == that.length)
				return true;
		}
	}
	return false;
}

bool String::StartsWith(const String &that)
{
	return Contains(that, 0, that.Length());
}

bool String::EndsWith(const String &that)
{
	return Contains(that, length - that.length);
}
