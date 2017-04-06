#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define INF 9999999
#define FOR(start,end,k) for(int i = start; i < end; i += k)
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	int bag[n+7];
	int table[(n+7)*2] = {0};
	int cnt = 0;
	int highest = -INF;
	for(int i = 0; i < n*2; ++i)
	{
		int k;
		scanf("%d",&k);
		table[k]++;
		if(table[k] == 2)
		{
			table[k] = 0;
			cnt--;
		}
		else
		{

			cnt++;
			highest = max(cnt,highest);
		}
	}
	printf("%d\n",highest);
}
