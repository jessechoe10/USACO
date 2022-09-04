#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for (ll i = 0; i < n; i++)

int main()
{
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	ll n;
	cin >> n;
	vl c(n);
	forn(i, n) cin >> c[i];
	ll sum = 0, best = LLONG_MAX, idx = -1;
	forn(i, n)
	{
		sum += c[i] - 1;
		if (sum < best)
		{
			idx = i;
			best = sum;
		}
	}
	ll start = idx + 1, ans = 0;
	rotate(c.begin(), c.begin() + start, c.end());
	queue<ll> q;
	forn(i, n)
	{
		forn(j, c[i])
		{
			q.push(i);
		}
		ll cur = q.front();
		ans += (i - cur) * (i - cur);
		q.pop();
	}
	cout << ans << endl;
}