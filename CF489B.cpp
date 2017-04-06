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
bool can(int sum,int remaining)
{
	return sum >= 0 && sum <= remaining * 9;
}
int main()
{
	int m,n;
	scanf("%d",&m);
	int A[m];
	FOR(0,m,1)
	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&n);
	int B[n];
	FOR(0,n,1)
	{
		scanf("%d",&B[i]);
	}
	sort(A,A+m);
	sort(B,B+n);
	int j = n-1;
	int i = m-1;
	int cnt = 0;
	while(i >= 0)
	{
		if(i < 0 || j < 0)
			break;
		if(abs(A[i] - B[j]) <= 1)
		{
			//printf("%d %d\n",A[i],B[j]);
			cnt++;
			i--;
			j--;
		}
		else if(A[i] > B[j])
		{
			i--;
		}
		else
			j--;
	}
	cout << cnt << endl;
	return 0;
}
