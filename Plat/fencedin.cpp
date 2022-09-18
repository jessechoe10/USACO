#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define sor(x) sort(begin(x), end(x))

int main(){
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	ll a, b, n, m; cin >> a >> b >> n >> m;
	vl v(n + 1), h(m + 1);
	forn(i, n) cin >> v[i + 1];
	forn(i, m) cin >> h[i + 1];
	sor(v); sor(h);
	forn(i, n){
		v[i] = v[i + 1] - v[i];
	}
	forn(i, m){
		h[i] = h[i + 1] - h[i];
	}
	v[n] = a - v[n], h[m] = b - h[m];
	sor(v); sor(h); n++, m++;
	ll ans = (m - 1) * v[0] + (n - 1) * h[0];
	ll i = 1, j = 1;
	while(i < n && j < m){
		if(v[i] < h[j]){
			ans += v[i++] * (m - j);
		} else {
			ans += h[j++] * (n - i);
		}
	}
	cout << ans << endl;
}
