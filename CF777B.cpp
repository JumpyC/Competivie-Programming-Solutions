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
using namespace std;
typedef long long ll;
void display(int A[],int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << endl;
    }
}
int main()
{
    int n,d1[10] = {0},d2[10] = {0},d3[10] = {0},d4[10] = {0},cnt1,cnt2 = 0,s;
    char a[1002],b[1002];
    cin >> n;
    cnt1 = n;
    s = n;
    cin >> a >> b;

    for(int i = 0; i < n; ++i)
    {
        d1[a[i] - '0']++;
        d2[b[i] - '0']++;
        d3[a[i] - '0']++;
        d4[b[i] - '0']++;
    }
    //display(d1,10);
    for(int i = 0; i < 10; ++i)
    {
        for(int k = 0; k < d1[i]; ++k)
        {
            for(int j = 0; j < 10; ++j)
            {
                //cout << i << " " << j << endl;
                if(d2[j] > 0 && j > i)
                {

                    d2[j]--;
                    //cout << j << " : " << i << endl;
                    cnt2++;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 10; ++i)
    {
        for(int k = 0; k < d3[i]; ++k)
            for(int j = 0; j < 10; ++j)
            {
                if(d4[j] > 0 && j >= i)
                {
                    //cout << j << " "<< i << endl;
                    d4[j]--;
                    cnt1--;
                    break;
                }
            }
    }
    cout << cnt1 << endl << cnt2 << endl;
}
