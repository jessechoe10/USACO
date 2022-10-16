#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using pll = pair<ll, pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define pb push_back
#define f first
#define s second

const ll MAXN = 1000, INF = 1e9;

vector<pll> adj[MAXN];
ll n, m;

ll getCost(ll f){
	priority_queue<pl, vpl, greater<pl>> pq;
	vl dist(n, INF); dist[0] = 0; pq.push({0, 0});
	while(!pq.empty()){
		pl cur = pq.top(); pq.pop();
		for(pll edge: adj[cur.s]){
			if(edge.s.s < f){
				continue;
			}
			if(dist[cur.s] + edge.s.f < dist[edge.f]){
				dist[edge.f] = dist[cur.s] + edge.s.f;
				pq.push({dist[edge.f], edge.f});
			}
		}
	}
	return (1e6 * f) / dist[n - 1];
}

int main(){
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	cin >> n >> m;
	forn(i, m){
		ll a, b, c, f; cin >> a >> b >> c >> f; --a, --b; 
		adj[a].pb({b, {c, f}}); adj[b].pb({a, {c, f}});
	}
	ll ans = 0;
	FOR(i, 1, MAXN + 1){
		ans = max(ans, getCost(i));
	}
	cout << ans << endl;
}