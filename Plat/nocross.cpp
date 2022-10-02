#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(x), greater<ll>())
#define pb push_back

// https://usaco.guide/gold/PURS?lang=cpp

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return max(a,b); }
	ll n; vector<T> seg;
	void init(ll _n) { n = _n; seg.assign(2*n,ID); }
	void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(ll p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(ll l, ll r) {	// min on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int main(){
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	ll n; cin >> n;
	vl id1(n), id2(n), breeds(n);
	forn(i, n) cin >> id1[i], --id1[i];
	forn(i, n) cin >> id2[i], breeds[--id2[i]] = i;
	Seg<ll> dp; dp.init(n + 1);
	forn(i, n){
		vl indices;
		FOR(j, max(0LL, id1[i] - 4), min(n, id1[i] + 5)){
			indices.pb(breeds[j]);
		}
		rsor(indices);
		for(ll idx: indices){
			dp.upd(idx + 1, dp.query(0, idx) + 1);
		}
	}
	cout << dp.query(0, n) << endl;
}
