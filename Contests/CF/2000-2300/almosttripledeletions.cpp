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

void solve(){
	ll n; cin >> n;
	vl a(n); readvi(a, n);
	vl dp(n + 1), cnt(n + 1);
	ll mxFreq = 0;
	forn(i, n){
		if((i + 1) % 2 && mxFreq <= i / 2){
			dp[i] = 1;
		} else {
			dp[i] = 0;
		}
		mxFreq = max(mxFreq, ++cnt[a[i]]);
	}
	forn(i, n){
		mxFreq = 0;
		vl freq(n + 1);
		if(dp[i]){
			FOR(j, i + 1, n + 1){
				if((j - i) & 1 && mxFreq <= (j - i) / 2 && (j == n || a[i] == a[j])){
					dp[j] = max(dp[j], dp[i] + 1);
				}
				if(j < n) mxFreq = max(mxFreq, ++freq[a[j]]);
			}
		}
	}
	cout << max(0LL, dp[n] - 1) << endl;
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
