// 0/1 Knapsack dynamic programming along with the sequence of the weights selected printed to output!

#include<stdio.h>
#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	//Visual studio compiler wont let you declare variable length arrays!!
	int K[n + 1][W + 1];
	
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
			{
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
				
			}

			else
			{
				K[i][w] = K[i - 1][w];
				
			}

		}
	}

	int weight = W;
	i = n;
	while (i > 0)
	{
		if ((K[i][weight] - K[i - 1][weight - wt[i - 1]]) == val[i - 1])
		{
			weight = weight - wt[i - 1];
			i = i - 1;
			cout << i << endl;
		}
		else
		{
			i = i - 1;
		}
	}
	return K[n][W];
}

int main()
{
	//int val[] = {10,20,60,80};
	//int wt[] = {1, 2, 4,5};
	//int W = 6; 

	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 60;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n) << endl;
	return 0;
}
