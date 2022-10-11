/*
 * Tips:
 * 1. Don't throw
 * 2. Don't sell
 * 3. Stop malding
 * 4. Get better
 * 5. Cope harder
 * 6. Skill issue
 * 7. You're ass
 * 8. Grind more
 * 9. You're not that guy
 * 10. Don't quit
 * 11. Become him
 * 12. You might be him
 * 13. No you're not
 * 14. Practice more
 * 15. Avoid silly shit
 * 16. Get better at CP
 * 17. Pass Gold
 * 18. Make Camp
 * 19. Make IOI
 * 20. You're him
 */

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using str = string;
using vb = vector<bool>;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<str>;
using ppl = pair<pl, ll>;
using plpl = pair<pl, ll>;
 
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

struct Math {
	ll MOD, MAXN; vl fact;
	Math(){
		this -> MOD = 1e9 + 7;
		this -> MAXN = 2e5;
	}
	Math(ll MOD, ll MAXN){
		this -> MOD = MOD;
		this -> MAXN = MAXN;
	}
	ll ceil(ll a, ll b){
		return (a + b - 1) / b;
	}
	ll add(ll a, ll b){
		return (a + b) % MOD;
	}
	ll mult(ll a, ll b){
		return ((a % MOD) * (b % MOD)) % MOD;
	}
	ll sub(ll a, ll b){
		return (a + b + MOD) % MOD;
	}
	ll pow(ll a, ll b){
		ll cur = 1;
		while(b){
			if(b & 1) cur *= a, cur %= MOD;
			a *= a, a %= MOD, b >>= 1;
		}
		return cur;
	}
	ll div(ll a, ll b){
		return mult(a, pow(b, MOD - 2));
	}
	void genFact(){
		fact.pb(1);
		FOR(i, 1, MAXN + 1) fact.pb(fact.back() * i);
	}
	ll factorial(ll n){
		return fact[n];
	}
	ll choose(ll a, ll b){
		return mult(div(factorial(a), factorial(b)), div(1LL, factorial(a - b)));
	}
	ll gcd(ll a, ll b){
		return __gcd(a, b);
	}
	ll lcm(ll a, ll b){
		return (a * b) / gcd(a, b);
	}
};

// https://usaco.guide/gold/PURS?lang=cpp

template<class T>
class BIT {
	private:
		ll size;
		vector<T> bit;
		vector<T> arr;
	public:
		BIT(ll size) : size(size), bit(size + 1), arr(size) { }

		/** Sets the value at index ind to val. */
		void set(ll ind, ll val) {
			add(ind, val - arr[ind]);
		}

		/** Adds val to the element at index ind. */
		void add(ll ind, ll val) {
			arr[ind] += val;
			ind++;
			for (; ind <= size; ind += ind & -ind) {
				bit[ind] += val;
			}
		}

		/** @return The sum of all values in [0, ind]. */
		T pref_sum(ll ind) {
			ind++;
			T total = 0;
			for (; ind > 0; ind -= ind & -ind) {
				total += bit[ind];
			}
			return total;
		}
};

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

// https://usaco.guide/gold/dsu?lang=cpp

struct DSU {
	vector<ll> e;
	DSU(ll N) { e = vector<ll>(N, -1); }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)]; }

	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

bool works(ll x){
	return true;
}

ll minBS(ll l, ll h){
	ll ans = h;
	while(l <= h){
		ll m = l + (h - l) / 2;
		if(works(m)){
			ans = m;
			h = m - 1;
		} else {
			l = m + 1;
		}
	} 
	return ans;
}

ll maxBS(ll l, ll h){
	ll ans = l;
	while(l <= h){
		ll m = l + (h - l) / 2;
		if(works(m)){
			ans = m;
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
	return ans;
}

void solve(){
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1; 
	// cin >> t;
	forn(i, t){
		solve();
	}
}

/* stuff you should look for (inspired by Benq)
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
