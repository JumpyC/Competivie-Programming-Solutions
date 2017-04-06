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
#include <iomanip>
#define INF numeric_limits<long long>:: max()
#define size 100007
using namespace std;
typedef long long ll;
int s1,s2;
void display(vector<int> A,int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    ll n,in;
    cin >> n;
    vector<ll> segment;
    for(int i = 0; i < n; ++i)
    {
    	cin >> in;
    	segment.push_back(in);
    }
    sort(segment.begin(),segment.end());
    for(int i = 0; i < n - 2; ++i)
    {
    	// 0 1 2
    	ll A = segment[i], B = segment[i+1], C = segment[i+2];
    	if(segment[i] + segment[i+1] > segment[i+2])
    	{
    		cout << "YES" << endl;
    		return 0;
    	}
    }
    cout << "NO" << endl;
}
