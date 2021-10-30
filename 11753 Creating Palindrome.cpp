#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int N, K, tem, cnt = 1;
vi ve;
int sol(int i, int j, int cnt)
{
	if (cnt > K)
		return 1e8;
	if (i >= j)
		return 0;
	if (ve[i] == ve[j])
		return sol(i + 1, j - 1, cnt);
	return min(1 + sol(i, j - 1, cnt + 1), 1 + sol(i + 1, j, cnt + 1));
}
void solve()
{
	cin >> N >> K;
	ve = vi(N);
	for (auto& it : ve)
		cin >> it;
	tem = sol(0, N - 1, 0);
	if (tem == 0)
		cout << "Case " << cnt++ << ": Too easy\n";
	else if (tem > K)
		cout << "Case " << cnt++ << ": Too difficult\n";
	else
		cout << "Case " << cnt++ << ": " << tem << "\n";

}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
