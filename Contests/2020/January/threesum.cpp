#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define f first
#define s second

const ll MAXN = 5000, MAXA = 1e6;

ll dp[MAXN + 1][MAXN + 1], cnt[2 * MAXA + 1];

int main(){
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	ll n, q; cin >> n >> q;
	vl a(n); forn(i, n) cin >> a[i];
	forn(i, n){
		FOR(j, i + 1, n){
			ll d = MAXA - (a[i] + a[j]);
			if(d <= 2 * MAXA && d >= 0){
				dp[i + 1][j + 1] += cnt[d];
			}
			cnt[MAXA + a[j]]++;
		}
		FOR(j, i + 1, n){
			cnt[MAXA + a[j]]--;
		}
	}
	FOR(i, 1, n + 1){
		FOR(j, 1, n + 1){
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	forn(i, q){
		ll a, b; cin >> a >> b;
		cout << dp[b][b] - dp[a - 1][b] - dp[b][a - 1] + dp[a - 1][a - 1] << endl;
	}
}
