#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b){
	ll cur = 1;
	while(b){
		if(b & 1) cur *= a, cur %= MOD;
		a *= a, a %= MOD, b >>= 1; 
	}
	return cur;
}

int main(){
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	ll n; cin >> n;
	vl ps(2 * n + 1), ok(2 * n + 1);
	forn(i, n){
		ll l, r; cin >> l >> r;
		ps[l]++, ps[r]--; ok[r]++;
	}
	FOR(i, 1, 2 * n + 1){
		ps[i] += ps[i - 1];
	}
	ll tot = 0;
	FOR(i, 1, 2 * n + 1){
		if(ok[i]){
			tot += binpow(2, n - ps[i] - 1), tot %= MOD;
		}
	}
	cout << tot << endl;
}
