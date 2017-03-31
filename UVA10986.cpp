
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <stack>
#define INF numeric_limits<ll>::max() - 1
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> ii;
typedef vector<pll> vp;
struct Compare
{
	bool operator()(const pll A,const pll B)
	{
		return A.first > B.first;
	}
};
ll dijsktra(vector<vp > graph,int src,int target)
{
	priority_queue<pll,vector<pll>,Compare> pq;
	vector<ll> sfs(graph.size(),INF);
	vector<bool> isCalculated(graph.size(),false);
	sfs[src] = 0;
	pq.push(pll(sfs[src],src));
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		isCalculated[u] = true;
		pq.pop();
		for(vector<pll>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			int v = it->first;
			int w = it->second;
			if(!isCalculated[v] && w + d < sfs[v])
			{
				sfs[v] = w + d;
				pq.push(pll(sfs[v],v));
			}
		}
	}
	return sfs[target];
}
int main()
{
	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; ++i)
	{
		int N,M,S,T;
		cin >> N >> M >> S >> T;
		vector<vp > graph(N,vp());
		for(int j = 0; j < M; ++j)
		{
			ll a,b,w;
			cin >> a >> b >> w;
			graph[a].push_back(pll(b,w));
			graph[b].push_back(pll(a,w));
		}
		ll ssp = dijsktra(graph,S,T);
		cout << "Case #"<<i << ": ";
		if(ssp != INF)
			cout << ssp << endl;
		else
			cout << "unreachable\n";
	}
    return 0;
}
//using g++ main.cpp -o main -std=c++11
