#include<bits/stdc++.h>
using namespace std;
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
struct Highways
{
	double cost;
	int from, to;
	bool operator<(const Highways& e)const
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
	int N, M, u, v; cin >> N;
	DSU us;
	vector < pair<int, int>>ve(N), ans;
	vector< Highways>ve2;
	for (auto& it : ve)
		cin >> it.first >> it.second;
	cin >> M;
	while (M--)
		cin >> u >> v, us.MergeGroups(u, v);
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			ve2.push_back({ sqrt(pow(ve[i].first - ve[j].first, 2) + pow(ve[i].second - ve[j].second, 2)), i + 1, j + 1 });
	sort(all(ve2));
	for (int i = 0; i < ve2.size(); i++)
		if (!us.SameGroup(ve2[i].from, ve2[i].to))
			us.MergeGroups(ve2[i].from, ve2[i].to), ans.push_back({ ve2[i].from, ve2[i].to });
	if (!ans.size())
		cout << "No new highways need\n";
	else
		for (auto& it : ans)
			cout << it.first << " " << it.second << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
	{
		solve();
		if (T)
			cout << "\n";
	}
}
