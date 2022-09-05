// YoRepi7

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<string>;
 
#define forn(i, n) for (ll i = 0; i < n; i++)
#define rofn(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ROF(i, b, a) for (ll i = b; i >= a; i--)
#define TRAV(a, x) for (auto &a : x)
#define ABC(c) for (char c = 'a'; c <= 'z'; c++)
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(x), greater<ll>())
#define pb push_back
#define mp make_pair
#define ins insert
#define ub upper_bound
#define lb lower_bound
#define len(x) (ll)(x).length()
#define sz(x) (ll)(x).size()
#define f first
#define s second
#define dbg(x) \
	TRAV(a, x) \
	cout << a << " "
#define prll(x) cout << x << endl
#define prllpi(p) cout << p.f << " " << p.s << endl
#define traverse(x) \
	TRAV(a, x)      \
	prllpi(a)
#define readvi(a, n) forn(i, n) cin >> a[i]
#define readvpi(a, n) forn(i, n) cin >> a[i].f >> a[i].s
#define gcd(a, b) __gcd(a, b)

ll ceil(ll a, ll b){
	return (a + b - 1) / b;
}

vl v; ll n;

bool works(ll x){
	ll cur = 0;
	forn(i, n){
		if(cur + (x - v[i]) < 0) return false;
		cur = cur + (x - v[i]);
	}
	return true;
}

void solve(){
	cin >> n;
	v.clear();
	forn(i, n){
		ll x; cin >> x;
		v.pb(x);
	}
	ll l = 0, r = 1e9, mx = r;
	while(l <= r){
		ll m = l + (r - l) / 2;
		if(works(m)){
			mx = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	ll sum = 0;
	forn(i, n) sum += v[i];
	ll q; cin >> q;
	forn(i, q){
		ll t; cin >> t;
		if(t < mx) cout << -1 << endl;
		else cout << ceil(sum, t) << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// ll t; cin >> t;
	// forn(i, t){
	// 	solve();
	// }
	solve();
}
