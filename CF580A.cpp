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
        int n,prev,maxsofar = 0,currmax = 1;
        scanf("%d",&n);
        scanf("%d",&prev);
        for(int i = 1; i < n; ++i)
        {
            int curr;
            scanf("%d",&curr);
            if(curr >= prev)
            {
                prev = curr;
                currmax++;
            }
            else
            {
                maxsofar = max(maxsofar,currmax);
                currmax = 1;
                prev = curr;
            }

        }
        maxsofar = max(maxsofar,currmax);
        printf("%d\n",maxsofar);
        return 0;
    }
