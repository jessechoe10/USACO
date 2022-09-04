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
#define sz(x) x.size()

const ll MAXN = 1e5, INF = 1e18;

vl adj[MAXN];
ll files, isFile[MAXN], len[MAXN], dp1[MAXN], dp2[MAXN], res;

ll dfs1(ll v, ll cur){
	dp1[v] = cur + len[v];
	for(ll u: adj[v]) dfs1(u, dp1[v]);
	return dp1[v];
}

ll dfs2(ll v){
	if(!sz(adj[v])){
		return 1;
	}
	ll sum = 0;
	for(ll u: adj[v]){
		sum += dfs2(u);
	}
	return dp2[v] = sum;
}

void dfs(ll v, ll d){
	res = min(res, d);
	for(ll u: adj[v]){
		if(isFile[u]) continue;
		ll newd = d - (len[u] * dp2[u]) + 3 * (files - dp2[u]);
		dfs(u, newd);
	}
}

int main(){
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);
	ll n; cin >> n;
	forn(i, n){
		string s; cin >> s;
		len[i] = s.length();
		ll m; cin >> m;
		forn(j, m){
			ll e; cin >> e;
			adj[i].pb(--e);
		}
		if(!m){
			isFile[i] = true, files++;
		} else {
			len[i]++;
		}
	}
	len[0] = 0; dfs1(0, 0);
	res = 0; forn(i, n) if(isFile[i]) res += dp1[i];
	dfs2(0); dfs(0, res);
	cout << res << endl;
}