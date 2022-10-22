#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define TRAV(a, x) for(auto& a: x)
#define pb push_back

const ll MAXN = 1000, MAXT = 1000, INF = 1e9;

vl adj[MAXN];
ll dp[MAXN][MAXT + 1];

int main(){
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	ll n, m, c; cin >> n >> m >> c;
	vl moonies(n); forn(i, n) cin >> moonies[i];
	forn(i, m){
		ll a, b; cin >> a >> b;
		--a, --b; adj[b].pb(a);
	}
	forn(i, n){
		forn(j, MAXT + 1){
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0; ll ans = 0;
	FOR(j, 1, MAXT + 1){
		forn(i, n){
			for(ll u: adj[i]){
				dp[i][j] = max(dp[i][j], dp[u][j - 1] + moonies[i]);
			}
		}
		ans = max(ans, dp[0][j] - c * j * j);
	}
	cout << ans << endl;
}
