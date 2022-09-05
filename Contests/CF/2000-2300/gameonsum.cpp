// YoRepi7

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<string>;
 
#define forn(i, n) for (ll i = 0; i < n; i++)
#define rofn(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ROF(i, b, a) for (ll i = b; i >= a; i--)
#define TRAV(a, x) for (auto &a : x)
#define ABC(c) for (char c = 'a'; c <= 'z'; c++)
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(x), greater<ll>())
#define pb push_back
#define mp make_pair
#define ins insert
#define ub upper_bound
#define lb lower_bound
#define len(x) (ll)(x).length()
#define sz(x) (ll)(x).size()
#define f first
#define s second
#define dbg(x) \
	TRAV(a, x) \
	cout << a << " "
#define prll(x) cout << x << endl
#define prllpi(p) cout << p.f << " " << p.s << endl
#define traverse(x) \
	TRAV(a, x)      \
	prllpi(a)
#define readvi(a, n) forn(i, n) cin >> a[i]
#define readvpi(a, n) forn(i, n) cin >> a[i].f >> a[i].s
#define gcd(a, b) __gcd(a, b)

const ll MAXN = 2000, MOD = 1e9 + 7;

ll dp[MAXN + 1][MAXN + 1];

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

void solve(){
	ll n, m, k; cin >> n >> m >> k;
	forn(i, n + 1){
		forn(j, m + 1){
			dp[i][j] = 0;
		}
	}
	forn(i, n + 1) dp[i][i] = (i * k) % MOD, dp[i][0] = 0;
	FOR(i, 2, n + 1){
		FOR(j, 1, i){
			dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD) * binpow(2, MOD - 2);
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][m] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t; cin >> t;
	forn(i, t){
		solve();
	}
	// solve();
}
