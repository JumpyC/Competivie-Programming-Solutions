
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <stack>
#define INF numeric_limits<ll>::max() - 1
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef vector<ill> vp;
struct Compare
{
	bool operator()(const ill A,const ill B)
	{
		return A.second < B.second;
	}
};
void dijsktra(vector<vp > graph,int src,int target)
{
	vector<bool> isDone(graph.size()+1,false);
	vector<ll> sfs(graph.size()+1,INF);
	vector<ll> name(graph.size()+1,-1);
	priority_queue<ill,vector<ill>,greater<ill> > pq;
	stack<int> path;
	sfs[src] = 0;
	pq.push(ill(sfs[src],src));
	while(!pq.empty())
	{
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		isDone[u] = true;
		for(int i = 0; i < graph[u].size(); ++i)
		{
			ill p = graph[u][i];
			int v = p.first;
			int d = p.second;
			if(!isDone[v] && w + d < sfs[v])
			{
				sfs[v] = w + d;
				name[v] = u;
				pq.push(ill(sfs[v],v));
			}
		}
	}
	if(name[target] == -1)
	{
		cout << -1 << endl;
		return ;
	}
	for(int i = target; i != -1; i = name[i])
	{
		path.push(i);
	}
	while(!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
	
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<vp> graph(n+1,vp());
	for(int j = 0; j < m; ++j)
	{
			ll a,b,w;
			cin >> a >> b >> w;
			graph[a].push_back(ill(b,w));
			graph[b].push_back(ill(a,w));
	}
	dijsktra(graph,1,n);
    return 0;
}
