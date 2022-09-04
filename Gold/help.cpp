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

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b){
	ll cur = 1;
	while(b){
		if(b & 1){
			cur *= a, cur %= MOD;
		}
		a *= a, a %= MOD, b >>= 1;
	}
	return cur;
}

int main(){
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	ll n; cin >> n;
	vpl segs(n); vl dp(2 * n);
	forn(i, n) cin >> segs[i].f >> segs[i].s, --segs[i].f, --segs[i].s;
	forn(i, n) dp[segs[i].f]++, dp[segs[i].s]--;
	FOR(i, 1, 2 * n) dp[i] += dp[i - 1];
	ll ans = 0;
	forn(i, n){
		ans += binpow(2, n - 1 - dp[segs[i].s]);
		ans %= MOD;
	}
	cout << ans << endl;
}