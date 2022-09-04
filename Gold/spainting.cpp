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
		a *= a, a %= MOD;
		b >>= 1;
	}
	return cur;
}

int main(){
	freopen("spainting.in", "r", stdin);
	freopen("spainting.out", "w", stdout);
	ll n, m, k; cin >> n >> m >> k; --k;
	vl dp(n), psum(n + 1);
	forn(i, k){
		dp[i] = binpow(m, i + 1); dp[i] %= MOD;
		psum[i + 1] = psum[i] + dp[i];
		psum[i + 1] %= MOD;
	}
	FOR(i, k, n){
		dp[i] = ((psum[i] - psum[i - k] + MOD) % MOD * (m - 1)) % MOD;
		dp[i] %= MOD;
		psum[i + 1] = psum[i] + dp[i];
		psum[i + 1] %= MOD;
	}
	cout << (binpow(m, n) - dp[n - 1] + MOD) % MOD << endl;
}