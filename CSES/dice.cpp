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

struct Math {
	ll MOD, MAXN; vl fact, ifact;
	Math(){
		this -> MOD = 1e9 + 7;
		this -> MAXN = 2e5;
	}
	Math(ll MOD, ll MAXN){
		this -> MOD = MOD;
		this -> MAXN = MAXN;
	}
	ll ceil(ll a, ll b){
		return (a + b - 1) / b;
	}
	ll add(ll a, ll b){
		return (a + b) % MOD;
	}
	ll mult(ll a, ll b){
		return ((a % MOD) * (b % MOD)) % MOD;
	}
	ll sub(ll a, ll b){
		return (a - b + MOD) % MOD;
	}
	ll pow(ll a, ll b){
		ll cur = 1;
		while(b){
			if(b & 1) cur *= a, cur %= MOD;
			a *= a, a %= MOD, b >>= 1;
		}
		return cur;
	}
	ll div(ll a, ll b){
		return mult(a, pow(b, MOD - 2));
	}
	void genFact(){
		fact.pb(1); ifact.pb(1);
		FOR(i, 1, MAXN + 1){ 
			fact.pb(mult(fact.back(), i));
			ifact.pb(pow(fact[i], MOD - 2));
		}
	}
	ll factorial(ll n){
		return fact[n];
	}
	ll choose(ll a, ll b){
		return mult(mult(ifact[b], ifact[a - b]), fact[a]);
	}
	ll gcd(ll a, ll b){
		return __gcd(a, b);
	}
	ll lcm(ll a, ll b){
		return (a * b) / gcd(a, b);
	}
};

void solve(){
	ll n; cin >> n;
	Math mi; vl dp(n + 1); dp[0] = 1;
	FOR(i, 1, n + 1){
		FOR(j, 1, 7){
			if(i - j >= 0){
				dp[i] = mi.add(dp[i], dp[i - j]);
			}
		}
	}
	cout << dp[n] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1; 
	// ll t; cin >> t;
	forn(i, t){
		solve();
	}
}
