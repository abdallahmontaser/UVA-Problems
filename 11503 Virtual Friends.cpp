#include<bits/stdc++.h>
using namespace std;
const int MAXNODE = 1e5 + 5;
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
void solve()
{
	int M, id = 1; cin >> M;
	string u, v;
	map<string, int>ma;
	DSU us;
	while (M--)
	{
		cin >> u >> v;
		if (ma.find(u) == ma.end()) ma[u] = id++;
		if (ma.find(v) == ma.end()) ma[v] = id++;
		if (!us.SameGroup(ma[u], ma[v]))
			us.MergeGroups(ma[u], ma[v]);
		cout << us.GetSize(ma[u]) << "\n";
	}
}
int main()
{
	int T ; cin >> T;
	while (T--)
		solve();
}
