#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 1e5;

ll n, l, q, timer;
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

struct BIT {
	vl bit; ll n;
	BIT(ll n){
		this -> n = n;
		bit.assign(n, 0);
	}
	void upd(ll idx, ll x){
		for(; idx < n; idx = idx | (idx + 1)){
			bit[idx] ^= x;
		}
	}
	ll query(ll r){
		ll ans = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1){
			ans ^= bit[r];
		}
		return ans;
	}
};

int main(){
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
	cin >> n >> q;
	vl e(n); forn(i, n) cin >> e[i];
	forn(i, n - 1){
		ll a, b; cin >> a >> b;
		--a, --b; adj[a].pb(b), adj[b].pb(a);
	}
	preprocess(0);
	BIT bit(4 * n);
	forn(i, n){
		bit.upd(tin[i], e[i]);
		bit.upd(tout[i], e[i]);
	}
	forn(i, q){
		ll type, a, b; cin >> type >> a >> b; --a, --b;
		if(type == 1){
			b++;
			bit.upd(tin[a], e[a]);
			bit.upd(tout[a], e[a]);
			e[a] = b;
			bit.upd(tin[a], e[a]);
			bit.upd(tout[a], e[a]);
		} else {
			ll w = lca(a, b);
			cout << ((bit.query(tin[a])) ^ (bit.query(tin[b])) ^ e[w]) << endl;
		}
	}
}