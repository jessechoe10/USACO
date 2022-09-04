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

const ll INF = 1e18;

vpl cows;
ll n, ans, eq;

void solve(){
	sor(cows);
	forn(l, n){
		set<ll> y;
		FOR(r, l + 1, n){
			if(l < r - 1) y.insert(cows[r - 1].s);
			ll len = cows[r].f - cows[l].f;
			ll lo = max(cows[l].s, cows[r].s) - len, hi = min(cows[l].s, cows[r].s);
			if(lo > hi) continue;
			vl cur_y; for(auto& a: y) cur_y.pb(a);
			ll lft = 0, rgt = -1;
			while(lft < cur_y.size() && cur_y[lft] + 1 <= lo) lft++;
			while(rgt + 1 < cur_y.size() && cur_y[rgt + 1] - len <= lo) rgt++;
			while(true){
				++ans;
				ll yl = min(cows[l].s, cows[r].s), yr = max(cows[l].s, cows[r].s);
				if(lft <= rgt) yl = min(yl, cur_y[lft]), yr = max(yr, cur_y[rgt]);
				eq += (yr - yl == len);
				ll bottom = (lft < cur_y.size() ? cur_y[lft] + 1 : INF);
				ll top = (rgt + 1 < cur_y.size() ? cur_y[rgt + 1] - len : INF);
				ll change = min(bottom, top);
				if(change > hi) break;
				lft += (bottom == change);
				rgt += (top == change);
			}
		}
	}
}

int main(){
	cin >> n;
	forn(i, n){
		ll x, y; cin >> x >> y;
		cows.pb({x, y});
	}
	ans = n + 1;
	solve();
	forn(i, n) swap(cows[i].f, cows[i].s);
	solve();
	cout << ans - eq / 2 << endl;
}