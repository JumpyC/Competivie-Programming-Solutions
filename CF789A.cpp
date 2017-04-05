#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <stack>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 10e12
#define FOR(start,end,incre) for(int i = start; i < end; i += incre)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef vector<ill> vp;
int main()
{
	long long n,cnt = 0;
	double k;
	cin >> n >> k;
	long long p[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		cnt += ceil(p[i] / k);
	//	printf("%lld\n",(ll)ceil(p[i] / k));
	}
	printf("%lld\n",(ll)ceil(cnt/2.0));
}
