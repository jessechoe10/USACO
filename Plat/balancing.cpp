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

const ll MAXN = 1e5, INF = 1e18;

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

BIT<ll> bitL(MAXN + 1), bitR(MAXN + 1);

bool ok(ll m){
	ll l = 0, r = MAXN + 1, mid;
	while(l + 1 < r){
		mid = l + (r - l) / 2;
		ll lft = bitL.pref_sum(MAXN + 1), bl = bitL.pref_sum(mid);
		ll rgt = bitR.pref_sum(MAXN + 1), br = bitR.pref_sum(mid);
		ll bot = max(bl, br), top = max(lft - bl, rgt - br);
		if(bot > m && top > m) return false;
		if(bot <= m && top <= m) return true;
		if(top > m){
			l = mid;
		} else {
			r = mid;
		}
	}
	return false;
}

int main(){
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	ll n; cin >> n;
	vpl cows(n);
	set<ll> ycoords;
	forn(i, n){
		cin >> cows[i].f >> cows[i].s;
		ycoords.insert(cows[i].s);
	}
	map<ll, ll> mp;
	ll cnt = 1;
	for(auto& a: ycoords){
		mp[a] = cnt++;
	}
	sor(cows);
	forn(i, n){
		cows[i].s = mp[cows[i].s];
		bitR.add(cows[i].s, 1);
	}
	ll res = INF;
	forn(i, n){
		bitR.add(cows[i].s, -1);
		bitL.add(cows[i].s, 1);
		ll l = 0, r = n + 10, ans = INF;
		while(l + 1 < r){
			ll m = (l + r) / 2;
			if(ok(m)){
				ans = m;
				r = m;
			} else {
				l = m;
			}
		}
		res = min(res, ans);
	}
	cout << res << endl;
}
