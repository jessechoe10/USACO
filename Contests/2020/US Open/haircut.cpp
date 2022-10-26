#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back

struct BIT {
	vl bit; ll n;
	BIT(ll n){
		this -> n = n;
		bit.assign(n, 0);
	}
	void add(ll idx, ll dx){
		for(; idx < n; idx |= (idx + 1)) bit[idx] += dx;
	}
	ll query(ll r){
		ll ans = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) ans += bit[r];
		return ans;
	}
	ll query(ll l, ll r){
		return query(r) - query(l - 1);
	}
};

int main(){
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	ll n; cin >> n; vl a(n); 
	forn(i, n) cin >> a[i];
	BIT bit(n + 1); vl cnt(n + 1);
	forn(i, n){
		cnt[a[i]] += bit.query(a[i] + 1, n);
		bit.add(a[i], 1);
	}
	ll sum = 0;
	forn(i, n){
		cout << sum << endl;
		sum += cnt[i];
	}
}
