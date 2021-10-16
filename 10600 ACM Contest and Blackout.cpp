#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
const int MAXNODE = 1e3;
struct DSU
{
	int parent[MAXNODE];
	int GroupSize[MAXNODE];
	DSU()
	{
		for (int i = 0; i < MAXNODE; i++)
		{
			parent[i] = i;
			GroupSize[i] = 1;
		}
	}
	int FindLeader(int node)
	{
		if (parent[node] == node)
			return node;
		return parent[node] = FindLeader(parent[node]);
	}
	bool SameGroup(int u, int v)
	{
		return (FindLeader(u) == FindLeader(v));
	}
	void MergeGroups(int u, int v)
	{
		int leader1 = FindLeader(u), leader2 = FindLeader(v);
		if (leader1 == leader2)
			return;
		if (GroupSize[leader1] < GroupSize[leader2])
			swap(leader1, leader2);
		parent[leader2] = leader1;
		GroupSize[leader1] += GroupSize[leader2];
	}
	int GetSize(int node)
	{
		return GroupSize[FindLeader(node)];
	}
};
struct ACM
{
	int from, to, cost;
	bool operator<(const ACM& e)const
	{
		if (cost != e.cost)
			return cost < e.cost;
		else if (from != e.from)
			return from > e.from;
		else
			return to > e.to;
	}
};
void solve()
{
	int N, M, u, v, ans = 0, ans2 = INT_MAX, cnt, tem; cin >> N >> M;
	DSU us;
	vector < ACM>ve(M), edges;
	for (auto& it : ve)
		cin >> it.from >> it.to >> it.cost;
	sort(all(ve));
	for (int i = 0; i < M; i++)
		if (!us.SameGroup(ve[i].from, ve[i].to))
			us.MergeGroups(ve[i].from, ve[i].to), ans += ve[i].cost, edges.push_back(ve[i]);
	for (int i = 0; i < edges.size(); i++)
	{
		DSU us2;
		cnt =  tem = 0;
		for (int j = 0; j < M; j++)
		{
			if ((ve[j].cost != edges[i].cost) || (ve[j].from != edges[i].from) || (ve[j].to != edges[i].to))
			{
				if (!us2.SameGroup(ve[j].from, ve[j].to))
					us2.MergeGroups(ve[j].from, ve[j].to), cnt += ve[j].cost, tem++;
			}
		}
		if (tem == N - 1)
			ans2 = min(ans2, cnt);
	}
	cout << ans << " " << ans2 << "\n";
	
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
