#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef vector<ill> vp;
int main()
{
	ll a,b,h,l,t1,t2,cnt = 0;
	cin >> a >> b;
	 h = max(a,b);
	 l = min(a,b);
	while(h > 0 && l > 0)
	{
		h -= 2;
		l++;
		if(h >= 0 && l >= 0)
		{
			t1 = h,t2 = l;
			h = max(t1,t2),l = min(t1,t2);
			cnt++;
		}
	}
	cout << cnt << endl;
}
