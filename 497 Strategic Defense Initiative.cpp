#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define all(x)                 x.begin(),x.end()
#define allr(x)                x.rbegin(),x.rend()
#define clr(x,val)           memset((x),(val),sizeof(x))
const double EPS = 1e-7;
int Mod = 1e9 + 7;
int dx[] = { -1,-1,0,1,1, 1, 0,-1 };
int dy[] = { 0 , 1,1,1,0,-1,-1,-1 };
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
int dp[10000][10000], tem;
vi ve;
int sol(int i, int prev)
{
	if (i == ve.size())
		return 0;
	int& ret = dp[i][prev];
	if (ret != -1)
		return ret;
	if (ve[i] > ve[prev])
		ret = max(ret, 1 + sol(i + 1, i));
	ret = max(ret, sol(i + 1, prev));
	return ret;
}
string S;
void build(int i, int prev)
{
	if (i == ve.size())
		return;
	int ret = dp[i][prev];
	if (ve[i] > ve[prev] && ret == 1 + sol(i + 1, i))
	{
		cout << ve[i] << "\n";
		build(i + 1, i);
	}
	else
		build(i + 1, prev);
}
void solve()
{
	ve.clear();
	ve.push_back(-1);
	clr(dp, -1);
	while (getline(cin, S) && S != "")
	{
		stringstream line(S);
		line >> tem;
		ve.push_back(tem);
	}
	cout << "Max hits: " << sol(1, 0) << "\n";
	build(1, 0);
}
int main()
{
	fast();
	int T = 1; cin >> T;
	cin.ignore();
	cin.ignore();
	while (T--)
	{
		solve();
		if (T)
			cout << "\n";
	}
}
