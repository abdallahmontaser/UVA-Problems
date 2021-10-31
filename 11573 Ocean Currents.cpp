#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dx[] = { -1,-1,0,1,1, 1, 0,-1 };
int dy[] = { 0 , 1,1,1,0,-1,-1,-1 };
int N, M, Q, X1, Y1, X2, Y2, to_x, to_y;
string S;
vector<vi>ve, vis;
bool vaild(int i, int j)
{
	if (i >= 0 && j >= 0 && i < N && j < M && vis[i][j] == -1)
		return true;
	return false;
}
struct boat
{
	int cost, x, y;
	bool operator<(const boat& e)const
	{
		if (cost != e.cost)
			return cost > e.cost;
		else if (x != e.x)
			return x > e.x;
		else
			return y > e.y;
	}
};
int BFS(pair<int, int>st, pair<int, int>en)
{
	priority_queue<boat>qe;
	vis = vector<vi>(N, vi(M, -1));
	boat cur, tem;
	cur.cost = 0, cur.x = st.first, cur.y = st.second;
	qe.push(cur);
	while (!qe.empty())
	{
		cur = qe.top();
		qe.pop();
		if (vis[cur.x][cur.y] != -1)
			continue;
		vis[cur.x][cur.y] = cur.cost;
		if (cur.x == en.first && cur.y == en.second)
			break;
		for (int i = 0; i < 8; i++)
		{
			to_x = cur.x + dx[i];
			to_y = cur.y + dy[i];
			if (vaild(to_x, to_y))
			{
				if (i == ve[cur.x][cur.y])
				{
					tem.cost = cur.cost;
					tem.x = to_x;
					tem.y = to_y;
					qe.push(tem);
				}
				else
				{
					tem.cost = cur.cost + 1;
					tem.x = to_x;
					tem.y = to_y;
					qe.push(tem);
				}
			}
		}
	}
	return vis[en.first][en.second];
}
void solve()
{
	cin >> N >> M;
	ve = vector<vi>(N, vi(M));
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		for (int j = 0; j < M; j++)
			ve[i][j] = int(S[j]-'0');
	}
	cin >> Q;
	while (Q--)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		X1--, Y1--, X2--, Y2--;
		cout << BFS({ X1,Y1 }, { X2,Y2 }) << "\n";
	}
}
int main()
{
	solve();
}
