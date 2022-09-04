#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define pb push_back
#define forn(i, n) for (ll i = 0; i < n; i++)
#define sor(x) sort(begin(x), end(x))
#define rsor(x) sort(rbegin(x), rend(x))

ll score(vl bessie, vl elsie, bool round)
{
	ll n = bessie.size(), i = 0, j = 0, ans = 0;
	while (i < n && j < n)
	{
		bool found;
		if (round)
		{
			found = (bessie[i] < elsie[j]);
		}
		else
		{
			found = (bessie[i] > elsie[j]);
		}
		if (found)
		{
			ans++;
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	return ans;
}

int main()
{
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	ll n;
	cin >> n;
	set<ll> s;
	vl elsieA, elsieB;
	forn(i, n)
	{
		ll x;
		cin >> x;
		if (i < n / 2)
		{
			elsieA.pb(x);
		}
		else
		{
			elsieB.pb(x);
		}
		s.insert(x);
	}
	vl bessieA, bessieB;
	for (ll i = 1; i <= 2 * n; i++)
	{
		if (!s.count(i))
		{
			if (bessieB.size() == n / 2)
			{
				bessieA.pb(i);
			}
			else
			{
				bessieB.pb(i);
			}
		}
	}
	sor(elsieA);
	rsor(elsieB);
	rsor(bessieB);
	cout << score(bessieA, elsieA, 0) + score(bessieB, elsieB, 1) << endl;
}