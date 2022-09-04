#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back

const ll MAXN = 1e5, MOD = 1e9 + 7;

vl adj[MAXN];
ll dp[MAXN][3], vis[MAXN][3], color[MAXN];

ll dfs(ll v, ll c, ll parv, ll parc){
	if(c == parc || (color[v] != -1 && color[v] != c)){
		return 0;
	}
	if(dp[v][c] != -1){
		return dp[v][c];
	}
	dp[v][c] = 1;
	for(ll u: adj[v]){
		if(u == parv) continue;
		ll sum = 0;
		forn(j, 3){
			sum += dfs(u, j, v, c);
			sum %= MOD;
		}
		dp[v][c] *= sum;
		dp[v][c] %= MOD;
	}
	return dp[v][c];
}

int main(){
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	ll n, k; cin >> n >> k;
	forn(i, n - 1){
		ll a, b; cin >> a >> b; --a, --b;
		adj[a].pb(b), adj[b].pb(a);
	}
	forn(i, n){
		color[i] = -1;
		forn(j, 3){
			dp[i][j] = -1;
		}
	}
	forn(i, k){
		ll b, c; cin >> b >> c; --b, --c;
		color[b] = c;
	}
	ll ways = dfs(0, 0, -1, -1) + dfs(0, 1, -1, -1) + dfs(0, 2, -1, -1);
	ways %= MOD;
	cout << ways << endl;
}