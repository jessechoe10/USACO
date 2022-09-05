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

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = -1e18; T comb(T a, T b) { return max(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// min on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

void solve(){
	ll n; cin >> n;
	vl a(n); readvi(a, n);
	vl ps(n + 1);
	set<ll> s; s.insert(0);
	forn(i, n){
		ps[i + 1] = ps[i] + a[i];
		s.insert(ps[i + 1]);
	}
	map<ll, ll> mp; ll cnt = 0;
	TRAV(a, s) mp[a] = ++cnt;
	Seg<ll> st1; st1.init(n + 2);
	Seg<ll> st2; st2.init(n + 2);
	vl dp(n + 1), res(n + 2, -1e18); res[mp[0]] = 0;
	forn(i, n + 1){
		dp[i] = max({res[mp[ps[i]]], st1.query(0, mp[ps[i]] - 1) + i, st2.query(min(n + 1, mp[ps[i]] + 1), n + 1) - i});
		if(dp[i] - i > st1.query(mp[ps[i]], mp[ps[i]])){
			st1.upd(mp[ps[i]], dp[i] - i);
		}
		if(dp[i] + i > st2.query(mp[ps[i]], mp[ps[i]])){
			st2.upd(mp[ps[i]], dp[i] + i);
		}
		res[mp[ps[i]]] = max(res[mp[ps[i]]], dp[i]);
	}
	cout << dp[n] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t; cin >> t;
	forn(i, t){
		solve();
	}
	// solve();
}
