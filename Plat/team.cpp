#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

struct Math {
	ll MOD, MAXN; vl fact;
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
		fact.pb(1);
		FOR(i, 1, MAXN + 1) fact.pb(fact.back() * i);
	}
	ll factorial(ll n){
		return fact[n];
	}
	ll choose(ll a, ll b){
		return mult(div(factorial(a), factorial(b)), div(1LL, factorial(a - b)));
	}
	ll gcd(ll a, ll b){
		return __gcd(a, b);
	}
	ll lcm(ll a, ll b){
		return (a * b) / gcd(a, b);
	}
};


const ll MAXN = 1000, MOD = 1e9 + 9;

ll dp[MAXN + 1][MAXN + 1][11];

int main(){
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ll n, m, k; cin >> n >> m >> k;
	vl fj(n + 1), fk(m + 1);
	forn(i, n) cin >> fj[i + 1];
	forn(i, m) cin >> fk[i + 1];
	forn(i, n + 1) forn(j, m + 1) dp[i][j][0] = 1;
	Math mi(MOD, MAXN);
	FOR(i, 1, n + 1){
		FOR(j, 1, m + 1){
			FOR(s, 1, k + 1){
				dp[i][j][s] = mi.add(dp[i][j][s], dp[i - 1][j][s]);
				dp[i][j][s] = mi.add(dp[i][j][s], dp[i][j - 1][s]);
				dp[i][j][s] = mi.sub(dp[i][j][s], dp[i - 1][j - 1][s]);
				if(fj[i] > fk[j]){
					dp[i][j][s] = mi.add(dp[i][j][s], dp[i - 1][j - 1][s - 1]);
				}
			}
		}
	}
	cout << dp[n][m][k] << endl;
}
