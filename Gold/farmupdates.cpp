#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back
#define f first
#define s second
#define mp make_pair

const ll MAXN = 1e5;
bool relevant[MAXN];
ll ans[MAXN]; vl adj[MAXN];

void activate(ll u, ll q){
	if(relevant[u]) return;
	relevant[u] = true;
	ans[u] = max(ans[u], q);
	for(ll v: adj[u]){
		activate(v, q);
	}
}

int main(){
	ll n, q; cin >> n >> q;
	vpl edges; vl bad_edge(q), q1(q, -1), q2(q, -1);
	forn(i, n) relevant[i] = 1;
	forn(i, q){
		char c; cin >> c;
		if(c == 'A'){
			ll x, y; cin >> x >> y; --x, --y;
			edges.pb(mp(x, y));
		} else if(c == 'D'){
			ll x; cin >> x; --x, relevant[x] = 0, q1[i] = x;
		} else {
			ll e; cin >> e; --e, bad_edge[e] = 1, q2[i] = e;
		}
	}
	forn(i, edges.size()){
		if(!bad_edge[i]){
			ll a = edges[i].f, b = edges[i].s;
			adj[a].pb(b), adj[b].pb(a);
			if(relevant[a] || relevant[b]){
				activate(a, n); activate(b, n);
			}
		}
	}
	forn(i, n){
		if(relevant[i]) ans[i] = q;
	}
	rofn(i, q - 1){
		if(q1[i] != -1){
			activate(q1[i], i);	
		} else if(q2[i] != -1){
			ll a = edges[q2[i]].f, b = edges[q2[i]].s;
			adj[a].pb(b), adj[b].pb(a);
			if(relevant[a] || relevant[b]){
				activate(a, i); activate(b, i);
			}
		}
	}
	forn(i, n){
		cout << ans[i] << endl;
	}
}
