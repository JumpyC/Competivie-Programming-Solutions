#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define INF 9999999
#define FOR(start,end,k) for(int i = start; i < end; i += k)
using namespace std;
typedef long long ll;

int main()
{
	int n,cnt = 0;
	scanf("%d",&n);
	int arr[n];
	FOR(0,n,1)
	{
		scanf("%d",&arr[i]);
		if(arr[i] == 0)
			arr[i] = 1;
		else
		{
			arr[i] = - 1;
			cnt++;
		}
	}
	int local_max = 0;
	int global_max = -2;
	FOR(0,n,1)
	{
		local_max += arr[i]; // can't be local_max = max(local+arr[i],0) because you have to do exactly one move
		global_max = max(local_max,global_max);
		local_max = max(local_max,0);
	}
	printf("%d\n",global_max+cnt);
	return 0;
}
