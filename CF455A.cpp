#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n,max_n = 0,k;
	ll cnt[100007] = {0};
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> k;
		cnt[k]++;
		max_n = max(k,max_n);
	}
	ll f[max_n+7];
	f[0] = 0;
	f[1] = cnt[1];
	for(ll i = 2; i <= max_n; ++i)
	{
		f[i] = max(f[i-1],f[i-2] + cnt[i]*i);
		//printf("i = %lld f[%lld] = %lld cnt[%lld] = %lld\n",i,i,f[i],i,cnt[i]);
	}
	cout << f[max_n] << endl;
	return 0;
}
