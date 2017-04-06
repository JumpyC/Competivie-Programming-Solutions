  #include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <sstream>
#define INF 9999999
#define FOR(start,end,k) for(int i = start; i < end; i += k)
using namespace std;
typedef long long ll;
int cnt = 0;
template <class T>
class Pair
{
public:
	T first,second;
	void set(T _first, T _second)
	{
		first = _first;
		second = _second;
	}
};
int check(char *A,int i,int j)
{
	return A[i] == A[j] ? 1 : 0;
}
int main()
{
	char* A = new char[200009];
	cin >> A;
	vector <int> ans;
	int n,l,r,cumulative_sum[strlen(A)];
	cumulative_sum[0] = check(A,0,1);
	for(int i = 1; i < strlen(A); ++i)
	{
		cumulative_sum[i] = check(A,i,i+1) + cumulative_sum[i-1];
	}
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d",&l,&r);
		l -= 2;
		r -= 2;
		if(l < 0)
			ans.push_back(cumulative_sum[r]);
		else
			ans.push_back(cumulative_sum[r] - cumulative_sum[l]);
		//printf("%d - %d = %d\n",cumulative_sum[r-1],cumulative_sum[l-1],cumulative_sum[r-1] - cumulative_sum[l-1]);
	}

	for(int i = 0; i < ans.size(); ++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
