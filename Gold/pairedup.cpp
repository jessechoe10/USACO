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

const ll INF = 1e9;

ll k;

ll calc(vpl cows){
	ll n = cows.size();
	vl dp1(n + 1), dp2(n + 1);
	dp1[n] = 0, dp2[n] = -INF;
	rofn(i, n - 1){
		dp1[i] = dp1[i + 1], dp2[i] = dp2[i + 1];
		pl up = {cows[i].f + k, INF};
		ll ub = upper_bound(all(cows), up) - begin(cows);
		if(i == 0 || i == n - 1 || (cows[i + 1].f - cows[i - 1].f <= k) || !(n - i & 1)){
			dp1[i] = max(dp1[i], dp2[ub] + cows[i].s);
		}
		if(i == 0 || i == n - 1 || (cows[i + 1].f - cows[i - 1].f <= k) || (n - i & 1)){
			dp2[i] = max(dp2[i], dp1[ub] + cows[i].s);
		} 
	}
	if(n & 1){
		return dp2[0];
	} else {
		return dp1[0];
	}
}

int main(){
	ll t, n; cin >> t >> n >> k;
	vpl cow(n + 1, {0, 0});
	forn(i, n) cin >> cow[i + 1].f >> cow[i + 1].s;
	if(t == 1){
		ll l = 1, r = 1, ans = 0, cur = 1e9;
		while(l <= n && r <= n){
			if(cow[r].f - cow[r - 1].f > k){
				if((r - l) & 1) ans += cur;
				cur = 1e9;
				l = r;
			}
			if((r - l) & 1){
				// remove the guy placed at even prefix
				if(r < n && cow[r + 1].f - cow[r - 1].f <= k){
					cur = min(cur, cow[r].s);
				}
			} else {
				cur = min(cur, cow[r].s);
			}
			r++;
		}
		if((r - l) & 1) ans += cur;
		cout << ans << endl;
	} else {
		vpl cows; ll ans = 0;
		FOR(i, 1, n + 1){
			if(cow[i].f - cow[i - 1].f > k){
				ans += calc(cows);
				cows.clear();
			}
			cows.pb(cow[i]);
		}
		if(cows.size()) ans += calc(cows);
		cout << ans << endl;
	}
}