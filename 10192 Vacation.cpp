#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
string A, B;
int dp[101][101], si_A, si_B;
int sol(int i, int j)
{
	if (i == si_A || j == si_B)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	if (A[i] == B[j])
		ret = 1 + sol(i + 1, j + 1);
	ret = max(ret, sol(i + 1, j));
	ret = max(ret, sol(i, j + 1));
	return ret;
}
void solve()
{
	for (int i = 1;; i++)
	{
		getline(cin, A);
		if (A == "#")
			break;
		getline(cin, B);
		clr(dp, -1);
		si_A = A.size(), si_B = B.size();
		cout << "Case #" << i << ": you can visit at most " << sol(0, 0) << " cities.\n";
	}
}
int main()
{
		solve();
}
