#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rofn(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MOD = 1e9 + 7;

int main(){
	ll n; cin >> n;
	ll mx = 0, ans = 0;
	vl h(n); forn(i, n) cin >> h[i], mx = max(mx, h[i]);
	ll times = (n & 1) ? mx + 1 : 1;
	forn(x, times){
		vl ps(mx + 1, 1);
		forn(i, n){
			vl dp(mx + 1);
			forn(j, h[i] - x + 1){
				dp[j] = ps[h[i] - x - j];
			}
			if(i == n - 1) ans += dp[0];
			ps[0] = dp[0];
			forn(j, mx + 1){
				if(j) ps[j] = ps[j - 1] + dp[j];
				ps[j] %= MOD;
			}
		}
		ans %= MOD;
	}
	cout << ans << endl;
}