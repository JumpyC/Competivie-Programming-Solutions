#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#define INF numeric_limits<ll>::max() - 1
using namespace std;
typedef long long ll;
typedef pair<int,ll> ill;
typedef vector<ill> vp;
struct Compare
{
	bool operator()(const ill A,const ill B)
	{
		return A.second < B.second;
	}
};

ll dijsktra(vector<vp > graph,int src,int target)
{
	priority_queue<ill,vector<ill>,greater<ill>> pq;
	vector<long long> sfs(graph.size(),INF);
	sfs[src] = 0;
	pq.push(ill(src,sfs[src]));
	while(!pq.empty())
	{
		ll src_node_id = pq.top().first;
		ll src_sfs = pq.top().second;
		pq.pop();
		for(vector<ill >::iterator it = graph[src_node_id].begin(); it != graph[src_node_id].end(); ++it)
		{
			ll dest_node_id = it->first;
			ll distance = it->second;
			if(src_sfs + distance < sfs[dest_node_id])
			{
				sfs[dest_node_id] = src_sfs + distance;
				pq.push(ill(dest_node_id,sfs[dest_node_id]));
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
			graph[a].push_back(ill(b,w));
			graph[b].push_back(ill(a,w));
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
