// PatternMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define ASCIIFACTOR 48

//HackerRank Interview question 2
vector < int > frequency(string s)
{
	int veclength = 25;
	std::vector<int>FinalOutput(veclength, 0);
	int length = s.length();
	int i = 0;

	while (i < length)
	{
		if (((i +2) < length ) && s[i + 2] == '#')				//2 digit
		{
			if (((i + 3) < length) && s[i + 3] == '(')			//2 digit repeating
			{
				int count = s[i + 4] - ASCIIFACTOR;
				int temp1 = (s[i] -ASCIIFACTOR) * 10;
				int temp2 = temp1 + (s[i + 1] - ASCIIFACTOR);
				FinalOutput.at(temp2 - 1) = FinalOutput.at(temp2 - 1) + count;
				i = i + 6;
			}
			else							//2 digit nonrepeating
			{
				int temp1 = (s[i] - ASCIIFACTOR )* 10;
				int temp2 = temp1 + (s[i + 1] - ASCIIFACTOR);
				FinalOutput.at(temp2 - 1) = FinalOutput.at(temp2 - 1) + 1;
				i = i + 3;
			}
		}
		
		else if (((i + 1) < length) && s[i + 1] == '(')			//1 digit repeating
		{
			int count = s[i + 2] - ASCIIFACTOR;
			int vecposition = s[i] - ASCIIFACTOR; vecposition--;
			int vecvalue = FinalOutput[vecposition] + count;
			FinalOutput.at(vecposition) = vecvalue;
			i = i + 4;
		}
		
		else								//base simple case
		{
			int vecposition = s[i] - ASCIIFACTOR; vecposition--;
			int vecvalue = FinalOutput[vecposition] + 1;
			FinalOutput.at(vecposition) = vecvalue;
			i++;
		}
	}
	return FinalOutput;
}

void vectorofvectors() 
{
	std::vector<std::vector<int>>vectorarray;
}

int main()
{
	vector<int>myvec = frequency("2137(2)24#(2)");
	for (int i = 0; i < myvec.size(); i++) 
	{
		cout << myvec.at(i) << endl;
	}
    return 0;
}



