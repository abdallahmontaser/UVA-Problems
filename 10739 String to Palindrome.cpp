#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
string S;
int cnt=1, dp[1000][1000];
int sol(int i, int j)
{
	if (i >= j)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	if (S[i] == S[j])
		ret = sol(i + 1, j - 1);
	else
		ret = 1 + min({ sol(i + 1, j - 1),sol(i, j - 1), sol(i + 1, j) });
	return ret;
}
void solve()
{
	cin >> S;
	clr(dp, -1);
	cout << "Case " << cnt++ << ": " << sol(0, S.size() - 1) << "\n";
}
int main()
{
	int T ; cin >> T;
	while (T--)
		solve();
}
