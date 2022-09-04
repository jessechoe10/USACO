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

vl adj[MAXN + 1];
ll x, val[MAXN + 1], depth[MAXN + 1];

void dfs(ll u){
	val[u] = x; x--;
	reverse(all(adj[u]));
	for(ll v: adj[u]){
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int main(){
	ll n; cin >> n;
	forn(i, n){
		ll j; cin >> j;
		adj[j].pb(i);
	}
	x = n + 1; dfs(n);
	ll k = n + 1;
	cout << k << endl;
	forn(i, n){
		ll height = depth[0] - depth[i];
		cout << height * k + val[i] << endl;
	}
}