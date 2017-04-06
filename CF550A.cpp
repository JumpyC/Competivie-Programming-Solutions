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

int main()//
{
	char A[500007];
	char* out = "NO";
	scanf("%s",A);
	vector<int> p1,p2;
	int n = strlen(A);
	for(int i = 0; i < n-1; ++i)
	{

		if(A[i] == 'A' && A[i+1] == 'B')
		{
			p1.push_back(i);
		}
		if(A[i] == 'B' && A[i+1] == 'A')
		{
			p2.push_back(i);
		}
	}

	for(int i = p1.size()-1; i >= 0; --i)
	{
		int j = 0;
		bool found = false;
		while(j < p2.size() && !found)
		{
			//printf("%d %d\n",i,j);
			if(abs(p1[i] - p2[j]) > 1)
			{
				found = true;
			}
			j++;
		}
		if(found)
		{
			out = "YES";
			break;
		}

	}
	printf("%s\n",out);
	return 0;
}//
