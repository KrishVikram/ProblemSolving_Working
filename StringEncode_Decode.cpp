

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

//encode/decode string based on userinput!

string secureChannel(int operation, string message, string key)
{
	int length = message.length();
	std::string return_value = "-1";
	if (length == 0)
	{
		return return_value;
	}
	std::stringstream out_encode;
	std::stringstream out_decode;
	if (operation == 1)
	{
		int keylength = key.length();
		for (int i = 0; i < length; i++)
		{
			int keyvalue = 0;
			bool biskeypresent = false;
			if (keylength > i)
			{
				keyvalue = key[i] - 48;
				biskeypresent = true;
			}
			while (biskeypresent && keyvalue > 0)
			{
				out_encode << message[i];
				keyvalue--;
			}
			if (!biskeypresent)
			{
				out_encode << message[i];
			}
		}
		return_value = out_encode.str();
	}
	else if (operation == 2)
	{
		int keylength = key.length();
		int stringlength = 0;
		for (int i = 0; i < keylength; i++)
		{
			out_decode << message[stringlength];
			int keyvalue = key[i] - 48;
			while (keyvalue > 0)
			{
				stringlength++;
				keyvalue--;
			}
		}
		while (stringlength < length)
		{
			out_decode << message[stringlength];
			stringlength++;
		}
		return_value = out_decode.str();
	}

	return return_value;
}
int main() 
{
	std::string mystring = "123";
	std::string message = "open";
	secureChannel(1, message, mystring);
	return 0;
}