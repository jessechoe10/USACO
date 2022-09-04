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

const ll MAXN = 1e4;

ll max_div[MAXN + 1];
vl primes;

void sieve(){
	for(ll i = 2; i <= MAXN; i++){
		if(max_div[i] == 0){
			primes.pb(i);
			for(ll j = i; j <= MAXN; j += i){
				max_div[j] = i;
			}
		}
	}
}

int main(){
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	sieve();
	ll n, m; cin >> n >> m;
	vl dp(n + 1); dp[0] = 1;
	for(ll prime: primes){
		for(ll i = n; i >= prime; i--){
			ll cur = prime;
			while(cur <= i){
				dp[i] += dp[i - cur] * cur;
				dp[i] %= m;
				cur *= prime;
			}
		}
	}
	ll sum = 0;
	forn(i, n + 1){
		sum += dp[i]; sum %= m;
	}
	cout << sum << endl;
}