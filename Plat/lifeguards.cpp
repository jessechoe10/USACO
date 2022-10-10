#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(x), greater<ll>())
#define pb push_back
#define f first
#define s second

const ll MAXN = 1e5, MAXK = 100, INF = 1e9;

ll dp[MAXN][MAXK + 1], mx[MAXN][MAXK + 1];

int main(){
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	ll n, k; cin >> n >> k;
	vpl shifts(n); forn(i, n) cin >> shifts[i].f >> shifts[i].s;
	sor(shifts); vpl lg;
	for(pl shift: shifts){
		if(lg.size() && lg.back().s >= shift.s) continue;
		lg.pb(shift);
	}
	k -= (shifts.size() - lg.size());
	k = max(0LL, k); ll ans = 0, l = 0;
	forn(i, lg.size()){
		while(lg[l].s < lg[i].f) l++;
		forn(j, k + 1){
			if(j > i){ 
				dp[i][j] = -INF;
			} else {
				if(l < i) dp[i][j] = max(dp[i][j], dp[l][max(0LL, j - (i - l - 1))] + lg[i].s - lg[l].s);
				dp[i][j] = max(dp[i][j], (l ? mx[l - 1][max(0LL, j - (i - l))] : 0) + lg[i].s - lg[i].f);
			}
			mx[i][j] = dp[i][j];
			if(i && j) mx[i][j] = max(mx[i][j], mx[i - 1][j - 1]);
		}
		ans = max(ans, dp[i][max(0LL, k - ((ll)lg.size() - 1 - i))]);
	}
	cout << ans << endl;
}
