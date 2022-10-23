#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using qu = queue<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 1e5;

vpl adj[MAXN];

int main(){
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	ll n, m, c; cin >> n >> m >> c;
	vl s(n); forn(i, n) cin >> s[i];
	vl date(n), indegree(n);
	forn(i, c){
		ll a, b, x; cin >> a >> b >> x;
		--a, --b; adj[a].pb({b, x});
		indegree[b]++;
	}
	qu q;
	forn(i, n){
		date[i] = s[i];
		if(!indegree[i]) q.push(i);
	}
	while(!q.empty()){
		ll cur = q.front(); q.pop();
		for(pl u: adj[cur]){
			date[u.f] = max(date[u.f], date[cur] + u.s);
			--indegree[u.f]; if(!indegree[u.f]) q.push(u.f);
		}
	}
	forn(i, n){
		cout << date[i] << endl;
	}
}
