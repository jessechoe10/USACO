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

const ll MAXN = 5000, MOD = 1e9 + 7;

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

ll cnt[26][MAXN];

int main(){
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	ll n, m, k; cin >> n >> m >> k;
	vpl words(n);
	forn(i, n) cin >> words[i].f >> words[i].s, --words[i].s;
	vl dp(k + 1), ways(n); dp[0] = 1;
	forn(i, k + 1){
		forn(j, n){
			if(i - words[j].f >= 0){
				dp[i] += dp[i - words[j].f];
				dp[i] %= MOD;
			}
			if(i == k){
				ways[words[j].s] += dp[i - words[j].f];
				ways[words[j].s] %= MOD;
			}
		}
	}
	map<char, ll> mp; map<ll, char> seen; 
	ll cur = 0;
	forn(i, m){
		char c; cin >> c;
		if(!mp[c]){
			seen[cur++] = c;
		}
		mp[c]++;
	}
	vl sum(cur);
	forn(i, n){
		cnt[0][i] = binpow(ways[i], mp[seen[0]]);
		sum[0] += cnt[0][i], sum[0] %= MOD;
	}
	FOR(i, 1, cur){
		forn(j, n){
			cnt[i][j] = sum[i - 1] * binpow(ways[j], mp[seen[i]]), cnt[i][j] %= MOD;
			sum[i] += cnt[i][j], sum[i] %= MOD;
		}
	}
	cout << sum[cur - 1] << endl;
}