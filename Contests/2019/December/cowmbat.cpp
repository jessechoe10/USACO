#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)

const ll MAXN = 1e5, MAXM = 26, INF = 1e18;

ll cost[MAXM][MAXM], dp[MAXN + 1][MAXM], ps[MAXN + 1][MAXM];

int main(){
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
	ll n, m, kk; cin >> n >> m >> kk;
	string s; cin >> s;
	forn(i, m){
		forn(j, m){
			cin >> cost[i][j];
		}
	}
	vl presses(n + 1);
	forn(i, n){
		presses[i + 1] = s[i] - 'a';
	}
	FOR(i, 1, n + 1){
		forn(j, m){
			ps[i][j] = ps[i - 1][j];
		}
		ps[i][presses[i]]++;
	}
	forn(k, m){
		forn(i, m){
			forn(j, m){
				if(cost[i][k] + cost[k][j] < cost[i][j]){
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
	FOR(i, 1, n + 1){
		forn(j, m){
			dp[i][j] = INF;
		}
	}
	FOR(i, 1, n + 1){
		forn(j, m){
			if(i - kk < 0) continue;
			ll tot = 0;
			forn(k, m){
				tot += (ps[i][k] - ps[i - kk][k]) * cost[k][j];
			}
			forn(k, m){
				if(j == k){
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[presses[i]][j]);
				}
				dp[i][j] = min(dp[i][j], dp[i - kk][k] + tot);
			}
		}
	}
	ll ans = INF;
	forn(i, m){
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}
