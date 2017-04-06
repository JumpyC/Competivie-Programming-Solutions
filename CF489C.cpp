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
bool can(int sum,int remaining)
{
	return sum >= 0 && sum <= remaining * 9;
}
int main()
{
		int remaining,sum;
		scanf("%d %d",&remaining,&sum);
		int t_sum = sum;
		string minn;
		string maxx;
		for(int i = 0; i < remaining; ++i)
		{
			for(int k = 0; k <= 9; ++k)
			{
				if(((i == 0 && k != 0) || i > 0 || remaining == 1) && can(t_sum - k,remaining - i - 1))
				{
					//cout << i << endl;
					t_sum -= k;
					char tmp[2];
					minn += '0' + k;
					break;
				}
			}
		}
		//cout << "min : " << minn << endl;
		if(minn == "" || (remaining > 1 && minn[0] == '0'))
		{
			minn = "-1";
			maxx = "-1";
		}
		else
		{
			//reverse
			for(int i = remaining - 1; i >= 0; --i)
			{
				maxx += minn[i];
			}
			for(int i = remaining - 1; i >= 1; --i)
			{
				int next = maxx[i-1] - '0';
				int curr = maxx[i] - '0';
				//cout << maxx[i] << " ";
				if(next + curr > 9)
				{
					maxx[i-1] = '9';
					maxx[i] = '0' + (next+curr - 9);
				}
				else
				{
					maxx[i-1] = '0'+ (next + curr);
					maxx[i] = '0';
				}
				//cout << maxx[i] << endl;
			}
		}


	cout  <<  minn << " " << maxx << endl;
	return 0;
}
