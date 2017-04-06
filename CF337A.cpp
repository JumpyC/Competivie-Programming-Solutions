#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <stack>
#include <algorithm>
typedef long long ll;
using namespace std;
int main()
{
    int n,m,best = numeric_limits<int>::max();
    scanf("%d %d",&n,&m);
    int s[m];
    for(int i = 0; i < m; ++i)
    {
        scanf("%d",&s[i]);
    }
    sort(s,s+m);
    for(int i = 0; i <= m - n; ++i)
    {
        best = min(best,s[i + n - 1] - s[i]);
    }
    printf("%d\n",best);
    return 0;
}
