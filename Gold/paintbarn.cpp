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

const ll MAXN = 201;

ll dp[MAXN][MAXN], actual[MAXN][MAXN];

ll ps(ll x1, ll y1, ll x2, ll y2){
	ll ans = actual[x2][y2];
	if(y1) ans -= actual[x2][y1];
	if(x1) ans -= actual[x1][y2];
	if(x1 && y1) ans += actual[x1][y1];
	return ans;
}

int main(){

	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	ll n, k; cin >> n >> k;
	forn(i, n){
		ll x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		dp[x1][y1]++;
		dp[x1][y2]--;
		dp[x2][y1]--;
		dp[x2][y2]++;
	}
	ll ans = 0;
	forn(x, MAXN){
		forn(y, MAXN){
			if(x) dp[x][y] += dp[x - 1][y];
			if(y) dp[x][y] += dp[x][y - 1];
			if(x && y) dp[x][y] -= dp[x - 1][y - 1];
			ans += (dp[x][y] == k);
			if(dp[x][y] == k - 1){
				actual[x][y]++;
			} else if(dp[x][y] == k){
				actual[x][y]--;
			}
		}
	}
	forn(x, MAXN){
		forn(y, MAXN){
			if(x) actual[x][y] += actual[x - 1][y];
			if(y) actual[x][y] += actual[x][y - 1];
			if(x && y) actual[x][y] -= actual[x - 1][y - 1];
		}
	}
	vl left(MAXN), right(MAXN), bott(MAXN), top(MAXN);
	forn(l, MAXN){
		FOR(r, l + 1, MAXN){
			ll cur = 0, mx = 0;
			FOR(x, 1, MAXN){
				ll sum = ps(x - 1, l, x, r);
				cur = max(cur + sum, sum);
				mx = max(mx, cur);
				left[x] = max(left[x], max(left[x - 1], mx));
			}
			cur = 0, mx = 0;
			rofn(x, MAXN - 2){
				ll sum = ps(x, l, x + 1, r);
				cur = max(cur + sum, sum);
				mx = max(mx, cur);
				right[x] = max(right[x], max(right[x + 1], mx));
			}
			cur = 0, mx = 0;
			FOR(y, 1, MAXN){
				ll sum = ps(l, y - 1, r, y);
				cur = max(cur + sum, sum);
				mx = max(mx, cur);
				bott[y] = max(bott[y], max(bott[y - 1], mx));
			}
			cur = 0, mx = 0;
			rofn(y, MAXN - 2){
				ll sum = ps(l, y, r, y + 1);
				cur = max(cur + sum, sum);
				mx = max(mx, cur);
				top[y] = max(top[y], max(top[y + 1], mx));
			}
		}
	}
	ll add = 0;
	forn(i, MAXN - 1){
		add = max(add, left[i] + right[i + 1]);
		add = max(add, bott[i] + top[i + 1]);
	}
	cout << min((ll) 200 * 200, ans + add) << endl;
}