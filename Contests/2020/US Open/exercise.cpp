#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back

int main(){
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	ll n, m; cin >> n >> m;
	vl primes;
	FOR(i, 2, n + 1){
		bool ok = true;
		for(ll j = 2; j * j <= i; j++){
			if(i % j == 0){
				ok = false; break;
			}
		}
		if(ok) primes.pb(i);
	}
	vl dp(n + 1); dp[0] = 1;
	for(ll p: primes){
		ROF(i, n, p){
			ll cur = p;
			while(cur <= i){
				dp[i] += dp[i - cur] * cur, dp[i] %= m;
				cur *= p;
			}
		}
	}
	FOR(i, 1, n + 1) dp[i] += dp[i - 1], dp[i] %= m;
	cout << dp[n] << endl;
}
