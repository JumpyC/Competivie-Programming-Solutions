#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <sstream>
#define INF 9999999
#define FOR(start,end,k) for(int i = start; i < end; i += k)
using namespace std;
typedef long long ll;

int main()
{
	int n,k,smallest = 0;
	scanf("%d %d",&n,&k);
	vector<int> A;
	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d",&a);
		A.push_back(a);
	}
	for(int i = 1; i < n; ++i)
	{
		if(A[i] + A[i-1] < k)
		{
			int d = k - (A[i-1] + A[i]);

			A[i] += d;
			smallest += d;
		}
	}
	printf("%d\n",smallest);
	for(int i = 0; i < n; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
