/*
 * Tips:
 * 1. Don't throw
 * 2. Don't sell
 * 3. Stop malding
 * 4. Get better
 * 5. Cope harder
 * 6. Skill issue
 * 7. You're ass
 * 8. Grind more
 * 9. You're not that guy
 * 10. Don't quit
 * 11. Become him
 * 12. You might be him
 * 13. No you're not
 * 14. Practice more
 * 15. Avoid silly shit
 * 16. Get better at CP
 * 17. Pass Gold
 * 18. Make Camp
 * 19. Make IOI
 * 20. You're him
 */

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using str = string;
using vb = vector<bool>;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<str>;
using ppl = pair<pl, ll>;
using plpl = pair<pl, ll>;
 
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

const ll MAXN = 5e5, MOD = 998244353;

ll dp[MAXN][3];

void solve(){
	ll n; cin >> n;
	vl a(n); readvi(a, n);
	forn(i, n) ++a[i];
	forn(i, n + 2) forn(j, 3) dp[i][j] = 0;
	dp[0][0] = 1;
	forn(i, n){
		forn(j, 3){
			dp[a[i]][j] += dp[a[i]][j];
			dp[a[i]][j] %= MOD;
		}
		dp[a[i]][0] += dp[a[i] - 1][0];
		dp[a[i]][0] %= MOD;
		if(a[i] - 2 >= 0){
			dp[a[i]][1] += dp[a[i] - 2][0] + dp[a[i] - 2][2];
			dp[a[i]][1] %= MOD;
		}
		if(a[i] + 2 <= n + 1){
			dp[a[i]][2] += dp[a[i] + 2][1];
			dp[a[i]][2] %= MOD;
		}
		
	}
	ll res = 0;
	forn(i, n + 2){
		res += dp[i][0] + dp[i][1] + dp[i][2];
		res %= MOD;
	}
	cout << (res - 1 + MOD) % MOD << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// ll t = 1; 
	ll t; cin >> t;
	forn(i, t){
		solve();
	}
}

/* stuff you should look for (inspired by Benq)
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
