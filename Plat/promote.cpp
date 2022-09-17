#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

struct BIT {
	ll n; vl bit;
	BIT(ll n){
		this->n = n;
		bit.assign(n + 1, 0);
	}
	ll sum(ll r){
		ll ret = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
		return ret;
	}
	ll sum(ll l, ll r){
		return sum(r) - sum(l - 1);
	}
	void upd(ll idx, ll dx){
		for(; idx < n; idx = idx | (idx + 1)) bit[idx] += dx;
	}
};

const ll MAXN = 1e5;

vl adj[MAXN];
ll timer = 0, st[MAXN], en[MAXN];

void dfs(ll node, ll par){
	st[node] = ++timer;
	for(ll u: adj[node]){
		if(u != par){
			dfs(u, node);
		}
	}
	en[node] = ++timer;
}

int main(){
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	ll n; cin >> n;
	vpl cows(n);
	forn(i, n){
		cin >> cows[i].f;
		cows[i].s = i;
	}
	forn(i, n - 1){
		ll x; cin >> x; --x;
		adj[x].pb(i + 1);
		adj[i + 1].pb(x);
	}
	sort(all(cows), greater<pl>()); dfs(0, -1);
	BIT bit(2 * n + 2); vl res(n);
	forn(i, n){
		res[cows[i].s] = bit.sum(st[cows[i].s], en[cows[i].s]);
		bit.upd(st[cows[i].s], 1);
	}
	forn(i, n){
		cout << res[i] << endl;
	}
}
