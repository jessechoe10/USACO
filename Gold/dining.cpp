#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rofn(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 5e4, INF = 1e18;

vpl adj[MAXN];
ll dist[MAXN + 1], n, m, k;

void dsp(ll x){
	forn(i, x) dist[i] = INF;
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	pq.push({0, x});
	while(!pq.empty()){
		pl cur = pq.top(); pq.pop();
		for(pl u: adj[cur.s]){
			if(cur.f + u.s < dist[u.f]){
				dist[u.f] = cur.f + u.s;
				pq.push({dist[u.f], u.f});
			}
		}
	}
}

int main(){
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	cin >> n >> m >> k;
	forn(i, m){
		ll a, b, t; cin >> a >> b >> t; --a, --b;
		adj[a].pb({b, t}), adj[b].pb({a, t});
	}
	dsp(n - 1);
	forn(i, k){
		ll p, y; cin >> p >> y; --p;
		adj[n].pb({p, (dist[p] - y)});
	}
	vl prev(n);
	forn(i, n) prev[i] = dist[i];
	dsp(n);
	forn(i, n - 1){
		(dist[i] <= prev[i]) ? cout << 1 << endl: cout << 0 << endl;
	}
}