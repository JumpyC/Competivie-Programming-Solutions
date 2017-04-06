#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define INF 9999999
#define FOR(i,n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int main()
{

	int n,cut[3],dp[4007];
	fill(dp,dp+4007,-1);
	scanf("%d %d %d %d",&n,&cut[0],&cut[1],&cut[2]);
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		int curr_max = -INF;
		for(int j = 0; j < 3; ++j)
		{
			if(i - cut[j] >= 0)
				curr_max = max(curr_max,dp[i-cut[j]]);
		}
		dp[i] = 1 + curr_max;
	}
	printf("%d\n",dp[n]);
	return 0;
}
