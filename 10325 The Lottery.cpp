#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return (b / gcd(a, b)) * a;
}
ll N, M, ans, res;
int count_bit(int mask)
{
	int cnt = 0;
	for (int bit = 0; bit < M; bit++)
		if (mask & (1 << bit))
			cnt++;
	return cnt;
}
void solve()
{
	while (cin >> N >> M)
	{
		vi ve(M);
		ans = 0;
		for (auto& it : ve)
			cin >> it;
		for (int mask = 1; mask < (1 << M); mask++)
		{
			res = 1;
			for (int bit = 0; bit < M; bit++)
			{
				if (mask & (1 << bit))
				{
					res = lcm(res, ve[bit]);
					if (res > N)
					{
						res = 1;
						break;
					}
				}
			}
			if (res != 1)
			{
				if (count_bit(mask) % 2 == 0)
					ans -= (N / res);
				else
					ans += (N / res);
			}
		}
		cout << N-ans << "\n";
	}
}
int main()
{
	 solve();
}
