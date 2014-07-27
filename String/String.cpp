#include "String.h"
#include <cstring>
#include <cctype>



String::String(char *origin) :str(origin?strlen(origin)+1:80)
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
		length = (strlen(origin)+1) < capacity ? (strlen(origin)) : capacity;
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

String::operator char*() const
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


bool String::Contains(const String &that, int startPos, int endPos) const
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

bool String::StartsWith(const String &that) const
{
	return Contains(that, 0, that.Length());
}

bool String::EndsWith(const String &that) const
{
	return Contains(that, length - that.length);
}

int String::IndexOf(char c, int startPos) const
{
	for (int i = startPos; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int String::IndexOf(const String &str) const
{
	for (int i = 0; i <= length - str.length; i++)
	{
		if (Contains(str, i, i + str.length))
			return i;
	}
	return -1;
}

int String::LastIndexOf(char c) const
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int String::LastIndexOf(const String &that) const
{
	for (int i = length - that.length; i >= 0; i--)
	{
		if (Contains(that, i, i + that.length))
			return i;
	}
	return -1;
}

int String::IndexOfAny(const String &that) const
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < that.length; j++)
		{
			if (that.str[j] == str[i])
				return i;
		}
	}
	return -1;
}

int String::IndexWhere(Condition f) const
{
	for (int i = 0; i < length; i++)
	{
		if (f(str[i]))
			return i;
	}
	return -1;
}

String String::Take(int num)
{
	if (num>length)
		num = length;
	if (num == length)
		return *this;
	char *tmp = new char[num+1];
	for (int i = 0; i < num; i++)
		tmp[i] = str[i];
	tmp[num] = '\0';
	String newString = tmp;
	return newString;
}

String String::Drop(int num)
{
	if (!num)
		return *this;
	if (num > length)
		num = length;
	char *tmp = new char[length - num + 1];
	for (int i = num; i < length; i++)
		tmp[i-num] = str[i];
	tmp[length - num] = '\0';
	String newString = tmp;
	return newString;
}

String String::DropRight(int num)
{
	return Take(length - num);
}

String String::TakeRight(int num)
{
	return Drop(length - num);
}

String String::TakeWhile(Condition f)
{
	int num = 0;
	while (f(str[num++]));
	return Take(--num);
}

String String::DropWhile(Condition f)
{
	int num = 0;
	while (f(str[num++]));
	return Drop(--num);
}

String String::TakeRightWhile(Condition f)
{
	int num = 0;
	while (f(str[length-(num++)-1]));
	return TakeRight(--num);
}

String String::DropRightWhile(Condition f)
{
	int num = 0;
	while (f(str[length - (num++)-1]));
	return DropRight(--num);
}

String& String::Remove(int from, int count)
{
	if (count > length - from)
		count = length - from;
	for (int i = from; i < length-count; i++)
		str[i] = str[count + i];
	length -= count;
	return *this;
}

String& String::Insert(const String &string, int pos)
{
	if (str.Length() <= length + string.length)
		str.Resize(length + string.length + 1);

	for (int i = length + string.length; i >= pos+string.length; i--)
		str[i] = str[i - string.length];
	for (int i = pos; i < string.length + pos; i++)
		str[i] = string.str[i - pos];
	length += string.length;
	return *this;
}

String& String::PadLeft(int count, char c)
{
	char* tmp = new char[count + 1];
	for (int i = 0; i < count; i++)
		tmp[i] = c;
	tmp[count] = '\0';
	Insert(tmp, 0);
	return *this;
}

String& String::PadRight(int count, char c)
{
	char* tmp = new char[count + 1];
	for (int i = 0; i < count; i++)
		tmp[i] = c;
	tmp[count] = '\0';
	Insert(tmp, length);
	return *this;
}

String& String::Replace(char from, char to)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == from)
			str[i] = to;
	}
	return *this;
}

String& String::Replace(String from, String to)
{
	int ind = IndexOf(from);
	if (ind >= 0)
	{
		Remove(ind, from.length);
		Insert(to, ind);
		return(Replace(from, to));
	}
	else
		return *this;
}

Array<String> String::Split(char sep)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == sep)
			count++;
	}
	Array<String> strSplit(count + 1);
	count = 0;
	for (int i = 0; i <strSplit.Length(); i++)
	{
		int nextInd = IndexOf(sep, count)-count;
		if (nextInd < 0)
			nextInd = length-count;
	
		strSplit[i] = Drop(count).Take(nextInd);
		count += nextInd+1;
	}
	return strSplit;
}

String String::TrimStart()
{
	return DropWhile([](char c){return c == ' '; });
}

String String::TrimEnd()
{
	return DropRightWhile([](char c){return c == ' '; });
}

String String::Trim()
{

	return TrimEnd().TrimStart();
}

String String::Normalize()
{
	String tmp = Trim();
	tmp.Replace("  ", " ");
	return tmp;
}

ostream& operator<<(ostream& os, const String &string)
{
	os << (char*)string;
	return os;
}