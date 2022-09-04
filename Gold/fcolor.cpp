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

const ll MAXN = 2e5;

vl adj[MAXN], rev[MAXN];

queue<ll> q;

ll par[MAXN];

struct DSU {
	DSU(ll n){
		forn(i, n) par[i] = i;
	}
	ll find(ll v){
		if(v == par[v]){
			return v; 
		}
		return par[v] = find(par[v]);
	}
	void merge(ll a, ll b){
		a = find(a), b = find(b);
		if(a != b){
			if(rev[a].size() < rev[b].size()){
				swap(a, b);
			}
			for(ll u: rev[b]) par[u] = a, rev[a].pb(u);
			adj[a].insert(adj[a].end(), all(adj[b]));
			if(adj[a].size() > 1) q.push(a);
		}
	}
  	bool same(ll a, ll b){
		return find(a) == find(b);
	}
};

int main(){
	freopen("fcolor.in", "r", stdin);
	freopen("fcolor.out", "w", stdout);
	ll n, m; cin >> n >> m;
	forn(i, m){
		ll a, b; cin >> a >> b;
		--a, --b; adj[a].pb(b);
	}
	DSU dsu(n);
	forn(i, n){
		rev[i].pb(i);
		if(adj[i].size() > 1) q.push(i);
	}
	while(!q.empty()){
		ll cur = q.front(); if(adj[cur].size() <= 1){ q.pop(); continue; }
		ll x = adj[cur].back(); adj[cur].pop_back();
		if(!dsu.same(x, adj[cur].back())){
			dsu.merge(x, adj[cur].back());
		}
	}
	vl res(n); ll cur = 0;
	forn(i, n){
		if(!res[par[i]]) res[par[i]] = ++cur;
		cout << res[par[i]] << endl;
	}
}