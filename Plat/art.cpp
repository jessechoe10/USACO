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

const ll MAXN = 1000;

ll art[MAXN][MAXN], ps[MAXN + 1][MAXN + 1], paint[MAXN + 1][MAXN + 1];

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	ll n; cin >> n;
	forn(i, n) forn(j, n) cin >> art[i][j];
	vl upper(n * n + 1, n), lower(n * n + 1), 
	left(n * n + 1, n), right(n * n + 1),
	cnt(n * n + 1); upper[0] = 0, left[0] = 0;
	ll tot = 0;
	forn(i, n){
		forn(j, n){	
			ll c = art[i][j];
			if(c){
				if(cnt[c] == 0) tot++;
				cnt[c]++; upper[c] = min(upper[c], i + 1);
				lower[c] = i + 1; left[c] = min(left[c], j + 1);
				right[c] = max(right[c], j + 1);
			}
		}
	}
	ll ans = n * n - tot;
	FOR(c, 1, n * n + 1){
		if(c && cnt[c]){
			ps[lower[c]][right[c]]++;
			ps[lower[c]][left[c] - 1]--;
			ps[upper[c] - 1][right[c]]--;
			ps[upper[c] - 1][left[c] - 1]++;
		}
	}
	paint[n][n] = ps[n][n];
	for(ll j = n - 1; j >= 1; j--){
		paint[n][j] = paint[n][j + 1] + ps[n][j];
	}
	for(ll i = n - 1; i >= 1; i--){
		paint[i][n] = paint[i + 1][n] + ps[i][n];
		for(ll j = n - 1; j >= 1; j--){
			paint[i][j] = paint[i + 1][j] + paint[i][j + 1] - paint[i + 1][j + 1] + ps[i][j];
		}
	}
	FOR(i, 1, n + 1){
		FOR(j, 1, n + 1){
			ll color = art[i - 1][j - 1];
			if(color > 0 && cnt[color] > 0 && paint[i][j] >= 2){
				cnt[color] = 0;
			}
		}
	}
	FOR(c, 1, n * n + 1){
		if(cnt[c]) ans++;
	}
	cout << ans << endl;
}
