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

typedef pair<pl, ll> T;

// https://usaco.guide/gold/PURS?lang=cpp

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
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
	freopen("slingshot.in", "r", stdin);
	freopen("slingshot.out", "w", stdout);
	ll n, m; cin >> n >> m;
	vector<T> slingshot(n); vl ycoords;
	forn(i, n){
		cin >> slingshot[i].f.f >> slingshot[i].f.s >> slingshot[i].s;
		ycoords.pb(slingshot[i].f.s);
	}
	vector<T> piles(m); vl ans(m);
	forn(i, m){
		cin >> piles[i].f.f >> piles[i].f.s; piles[i].s = i;
		ycoords.pb(piles[i].f.s);
		ans[i] = abs(piles[i].f.s - piles[i].f.f);
	}
	sor(slingshot); sor(piles);
	sor(ycoords); map<ll, ll> mp; ll cur = 0;
	forn(i, ycoords.size()){
		if(!mp[ycoords[i]]) mp[ycoords[i]] = ++cur;
	}
	Seg<ll> s1, s2; s1.init(ycoords.size() + 1); s2.init(ycoords.size() + 1);
	ll j = 0; 
	forn(i, m){
		while(j < n && slingshot[j].f.f <= piles[i].f.f){
			s1.upd(mp[slingshot[j].f.s], slingshot[j].s - slingshot[j].f.f - slingshot[j].f.s);
			s2.upd(mp[slingshot[j].f.s], slingshot[j].s + slingshot[j].f.s - slingshot[j].f.f);
			j++;
		}
		ans[piles[i].s] = min(ans[piles[i].s], min(piles[i].f.f + piles[i].f.s + s1.query(0, mp[piles[i].f.s]), piles[i].f.f - piles[i].f.s + s2.query(mp[piles[i].f.s], ycoords.size())));
	}
	s1.init(ycoords.size() + 1); s2.init(ycoords.size() + 1);
	j = n - 1;
	rofn(i, m - 1){
		while(j >= 0 && slingshot[j].f.f >= piles[i].f.f){
			s1.upd(mp[slingshot[j].f.s], slingshot[j].s + slingshot[j].f.f - slingshot[j].f.s);
			s2.upd(mp[slingshot[j].f.s], slingshot[j].s + slingshot[j].f.s + slingshot[j].f.f);
			j--;
		}
		ans[piles[i].s] = min(ans[piles[i].s], min(-piles[i].f.f + piles[i].f.s + s1.query(0, mp[piles[i].f.s]), s2.query(mp[piles[i].f.s], ycoords.size()) - piles[i].f.f - piles[i].f.s));
	}
	forn(i, m){
		cout << ans[i] << endl;
	}
}
