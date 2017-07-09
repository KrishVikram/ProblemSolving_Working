
//Simple Run Length Encoding using C++ stream classes.

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

void *encode(char *src)
{
	int rLen;
	int len = strlen(src);
	int i; 
	int first;
	std::ostringstream out;
	for (i = 0; i < len; i++)
	{
		first = i;
		rLen = 1;
		while (i + 1 < len && src[i] == src[i + 1])
		{
			rLen++;
			i++;
		}
		out << rLen;
		out << src[first];
	}
	cout << out.str();

}

int main()
{
	char src[] = "geeeeeeeekkssssekkkkkss";
	encode(src);
	return 0;
}
