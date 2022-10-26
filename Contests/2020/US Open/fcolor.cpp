#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vl = vector<ll>;
using ql = queue<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back
#define all(x) begin(x), end(x)

const ll MAXN = 2e5;

vl adj[MAXN], dsu[MAXN]; ll par[MAXN];
ql q;

void merge(ll a, ll b){
	a = par[a], b = par[b];
	if(adj[a].size() < adj[b].size()) swap(a, b);
	for(ll node: dsu[b]) par[node] = a, dsu[a].pb(node);
	adj[a].insert(end(adj[a]), all(adj[b])); adj[b].clear();
	if(adj[a].size() > 1) q.push(a);
}

int main(){
	freopen("fcolor.in", "r", stdin);
	freopen("fcolor.out", "w", stdout);
	ll n, m; cin >> n >> m;
	forn(i, m){
		ll a, b; cin >> a >> b; --a, --b;
		adj[a].pb(b);
	}
	forn(i, n){
		par[i] = i; dsu[i].pb(i);
		if(adj[i].size() > 1) q.push(i);
	}
	while(!q.empty()){
		ll cur = q.front();
		if(adj[cur].size() <= 1){ q.pop(); continue;}
		ll x = adj[cur].back(); adj[cur].pop_back();
		if(par[x] == par[adj[cur].back()]) continue;
		merge(x, adj[cur].back());
	}
	ll cnt = 0; vl ans(n);
	forn(i, n){
		if(!ans[par[i]]) ans[par[i]] = ++cnt;
		cout << ans[par[i]] << endl;
	}
}
