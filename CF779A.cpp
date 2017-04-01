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
#define FOR(start,end,incre) for(int i = start; i < end; i += incre)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef vector<ill> vp;
int main()
{
	int A[6];
	int B[6];
	fill_n(A,6,0);
	fill_n(B,6,0);
	int n,k,total_A = 0,total_B = 0,cnt = 0;
	cin >> n;
	FOR(0,n,1)
	{
		cin >> k;
		A[k]++;
		total_A++;
	}
	FOR(0,n,1)
	{
		cin >> k;
		B[k]++;
		total_B++;
	}
	FOR(1,6,1)
	{
		int h = max(A[i],B[i]);
		int l = min(A[i],B[i]);
		int bal =  h - ((A[i] + B[i]) / 2);
		cnt += bal;
		if((h -= bal) != (l += bal))
		{
			cout << -1 << endl;
			return 0;
		}
	}
	if(total_A == total_B)
	{
		cout << cnt / 2 << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

