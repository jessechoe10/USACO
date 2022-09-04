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

typedef pair<pl, ll> Q;

const ll MAXN = 2e5 + 5;

ll ans[MAXN], deactive[MAXN], rem[MAXN];
bool active[MAXN], works[MAXN];
vl adj[MAXN];

void dfs(ll a, ll q){
	if(ans[a] == 0){
		ans[a] = q;
		for(ll u: adj[a]){
			dfs(u, q);
		}
	}
}

int main(){
	ll n, q; cin >> n >> q; vpl edges; 
	forn(i, MAXN){
		active[i] = true, works[i] = true;
		deactive[i] = -1, rem[i] = -1;
	}
	forn(i, q){
		char c; cin >> c;
		if(c == 'A'){
			ll x, y; cin >> x >> y;
			edges.pb({x, y});
		} else if(c == 'D'){
			ll v; cin >> v;
			active[v] = 0;
			deactive[i] = v;
		} else {
			ll v; cin >> v;
			rem[i] = v - 1;
			works[v - 1] = 0;
		}
	}
	forn(i, edges.size()){
		if(works[i]){
			adj[edges[i].f].pb(edges[i].s);
			adj[edges[i].s].pb(edges[i].f);
		}
	}
	FOR(i, 1, n + 1){
		if(active[i]){
			dfs(i, q);
		}
	}
	rofn(i, q - 1){
		if(deactive[i] != -1){
			dfs(deactive[i], i);
		} 
		if(rem[i] != -1){
			ll a = edges[rem[i]].f, b = edges[rem[i]].s;
			adj[a].pb(b), adj[b].pb(a);
			if(ans[a] != 0 || ans[b] != 0){
				dfs(a, i); dfs(b, i);
			}
		}
	}
	FOR(i, 1, n + 1){
		cout << ans[i] << endl;
	}
}