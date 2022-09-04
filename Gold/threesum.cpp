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

const ll MAXN = 5000, MAXA = 1e6;

ll dp[MAXN + 1][MAXN + 1], cnt[2 * MAXA + 1];

ll query(ll l, ll r){
	return dp[r][r] - dp[l - 1][r] - dp[r][l - 1] + dp[l - 1][l - 1];
}

int main(){
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	ll n, q; cin >> n >> q;
	vl a(n); forn(i, n) cin >> a[i];
	forn(i, n){
		FOR(j, i + 1, n){
			ll d = 3 * MAXA - (2 * MAXA + a[i] + a[j]);
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
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i][j] - dp[i - 1][j - 1];
		}
	}
	forn(i, q){
		ll l, r; cin >> l >> r;
		cout << query(l, r) << endl;
	}
}