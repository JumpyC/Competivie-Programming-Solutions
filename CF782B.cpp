#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef vector<ill> vp;
bool check(vector<ill> vec,double s)
{
	double l = vec[0].first - vec[0].second * s;
	double h = vec[0].first + vec[0].second * s;
	for(vector<ill>::iterator it = vec.begin() + 1; it != vec.end(); ++it)
	{
		//cout << l << " -- - " << h << endl;
		double lcl = it->first - it->second * s;
		double lch = it->first + it->second * s;
		if(lcl > h || lch < l)
		{
			return false;
		}
		h = min(h,lch);
		l = max(l,lcl);

	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	double b = 10e9,a = 0,v;

	vector<ill> vec(n,ill());
	double ans;

	for(int i = 0; i < n; ++i)
	{
		cin >> vec[i].first;
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> vec[i].second;
	}
	while(abs(b - a) > 10e-7)
	{
		v = (b+a)/2;
		if(check(vec,v))
		{
			b = v;
			ans = v;
		}
		else
		{
			a = v;
		}
	}
	cout << setprecision(12) << ans << endl;

}
