#include "String.h"


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
		length = strlen(origin) < capacity ? strlen(origin) : capacity;
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
