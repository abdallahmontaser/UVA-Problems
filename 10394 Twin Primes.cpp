#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int N = 2e8 + 5;
vector<bool>prime(N+5, true);
vector<pair<int, int>>ve(1e5 + 50);
void sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 4; i < N; i += 2)
		prime[i] = 0;
	for (int i = 3; i * i < N; i += 2)
	{
		if (prime[i])
			for (int j = i * i; j < N; j += i + i)
				prime[j] = 0;
	}
	int last = -1, idx = 0;
	for (int i = 2; i < N && idx <= 1e5; i++)
	{
		if (prime[i])
		{
			if (last != -1 && i - last == 2)
				ve[idx++] = { last,i };
			last = i;
		}
	}
}
void solve()
{
	int X; 
	while (cin >> X)
		cout << "(" << ve[X - 1].first << ", " << ve[X - 1].second << ")\n";
}
int main()
{
	sieve();
	solve();
}
