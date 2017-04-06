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
int gcd(int a,int b)
{
	if(a == 0)
		return b;
	return gcd(b%a,a);
}
int main()
{
   int s1,s2,d,cnt = 0;
   cin >> s1 >> s2 >> d;
   int gc = gcd(s1,s2);
   int lcm = s1 * s2 / gc;
   cout << d / lcm << endl;
}
