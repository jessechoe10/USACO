#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

typedef pair<pl, pl> T;

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
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	ll n, p; cin >> n >> p;
	vector<T> boards; vl ycoords, cost(p);
	forn(i, p){
		ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cost[i] = (x2 - x1) + (y2 - y1);
		boards.pb({{x1, y1}, {i, 1}}), boards.pb({{x2, y2}, {i, -1}});
		ycoords.pb(y1), ycoords.pb(y2);
	}
	sor(boards); vl dp(p); Seg<ll> seg;
	sor(ycoords); map<ll, ll> mp; ll cnt = 0;
	for(ll y: ycoords){
		if(!mp[y]) mp[y] = ++cnt;
	}
	seg.init(cnt + 1);
	for(T board: boards){
		if(board.s.s == 1){
			dp[board.s.f] = seg.query(0, mp[board.f.s]) + cost[board.s.f];
		} else {
			if(dp[board.s.f] > seg.query(mp[board.f.s], mp[board.f.s])){
				seg.upd(mp[board.f.s], dp[board.s.f]);
			}
		}
	}
	cout << 2 * n - seg.query(0, cnt) << endl;
}
