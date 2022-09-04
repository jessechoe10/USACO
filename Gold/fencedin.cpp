#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<int>;
using pl = pair<int, int>;
using vpl = vector<pl>;

#define pb push_back
#define f first
#define s second
#define forn(i, n) for (int i = 0; i < n; i++)
#define sor(x) sort(begin(x), end(x))
#define rsor(x) sort(begin(x), end(x))

struct DSU
{
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y)
	{ // union by size
		x = get(x), y = get(y);
		if (x == y)
			return false;
		if (e[x] > e[y])
			swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

vector<pair<int, pl>> edges;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vl h, v;
	v.pb(0), h.pb(0), v.pb(a), h.pb(b);
	forn(i, n)
	{
		int x;
		cin >> x;
		v.pb(x);
	}
	forn(i, m)
	{
		int x;
		cin >> x;
		h.pb(x);
	}

	sor(v);
	sor(h);
	forn(i, m + 1)
	{
		forn(j, n)
		{
			edges.pb({h[i + 1] - h[i], {(n + 1) * i + j, (n + 1) * i + j + 1}});
		}
	}
	forn(i, n + 1)
	{
		forn(j, m)
		{
			edges.pb({v[i + 1] - v[i], {j * (n + 1) + i, (j + 1) * (n + 1) + i}});
		}
	}
	DSU dsu((n + 1) * (m + 1));
	sor(edges);
	ll ans = 0;
	for (pair<int, pl> x : edges)
	{
		if (!dsu.same_set(x.s.f, x.s.s))
		{
			ans += x.f;
			dsu.unite(x.s.f, x.s.s);
		}
	}
	cout << ans << endl;
}