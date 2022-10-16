#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define f first
#define s second
#define pb push_back

typedef pair<pl, ll> pll;

const ll MAXN = 1e5;

ll n, m, l, q, timer;
vector<vl> up;
vl adj[MAXN], tin, tout;

// Found ETT/LCA code here: https://cp-algorithms.com/graph/lca_binary_lifting.html#algorithm

void dfs(ll v, ll p)
{
	tin[v] = timer++;
	up[v][0] = p;
	for (ll i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (ll u : adj[v]) {
		if (u != p)
			dfs(u, v);
	}
	tout[v] = timer++;
}

bool is_ancestor(ll u, ll v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (ll i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(ll root) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vl(l + 1));
	dfs(root, root);
}

// https://usaco.guide/gold/PURS?lang=cpp

template<class T>
class BIT {
	private:
		ll size;
		vector<T> bit;
		vector<T> arr;
	public:
		BIT(ll size) : size(size), bit(size + 1), arr(size) { }

		/** Sets the value at index ind to val. */
		void set(ll ind, ll val) {
			add(ind, val - arr[ind]);
		}

		/** Adds val to the element at index ind. */
		void add(ll ind, ll val) {
			arr[ind] += val;
			ind++;
			for (; ind <= size; ind += ind & -ind) {
				bit[ind] += val;
			}
		}

		/** @return The sum of all values in [0, ind]. */
		T pref_sum(ll ind) {
			ind++;
			T total = 0;
			for (; ind > 0; ind -= ind & -ind) {
				total += bit[ind];
			}
			return total;
		}
		T pref_sum(ll a, ll b){
			return pref_sum(b) - pref_sum(a - 1);
		}
};

int main(){
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> n >> m;
	vl t(n); forn(i, n) cin >> t[i], --t[i];
	vl cows[n]; forn(i, n) cows[t[i]].pb(i);
	forn(i, n - 1){
		ll a, b; cin >> a >> b; --a, --b;
		adj[a].pb(b); adj[b].pb(a);
	}
	vector<pll> friends[n];
	forn(i, m){
		ll a, b, c; cin >> a >> b >> c;
		--a, --b, --c; friends[c].pb({{a, b}, i});
	}
	preprocess(0); 
	BIT<ll> bit(4 * n); vl ans(m);
	forn(i, n){
		for(ll u: cows[i]){
			bit.set(tin[u], 1);
			bit.set(tout[u], -1);
		}
		for(pll u: friends[i]){
			ll mid = lca(u.f.f, u.f.s);
			if(bit.pref_sum(tin[mid], tin[u.f.f]) + bit.pref_sum(tin[mid], tin[u.f.s])){
				ans[u.s] = 1;
			}
		}
		for(ll u: cows[i]){
			bit.set(tin[u], 0);
			bit.set(tout[u], 0);
		}
	}
	forn(i, m){
		cout << ans[i];
	}
	cout << endl;
}