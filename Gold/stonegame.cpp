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
#define sor(x) sort(all(x))

int main(){
	ll n; cin >> n;
	ll mx = 0;
	vl a(n); forn(i, n) cin >> a[i], mx = max(mx, a[i]);
	vl dp(mx + 1); forn(i, n) dp[a[i]]++;
	FOR(i, 1, mx + 1) dp[i] += dp[i - 1];
	ll ans = 0;
	FOR(x, 1, mx + 1){
		vl counts, odd; counts.pb(0);
		for(ll t = 1; x * t <= mx; t++){
			counts.pb(dp[min(mx, x * (t + 1) - 1)] - dp[min(mx, x * t - 1)]);
		}
		FOR(c, 1, counts.size()){
			if(counts[c] & 1) odd.pb(c);
		}
		if(odd == vl{1} || (odd.size() == 2 && odd[0] + 1 == odd[1])){
			ans += counts[odd.back()];
		}
	}
	cout << ans << endl;
}