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
