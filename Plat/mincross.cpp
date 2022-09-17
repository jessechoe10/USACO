#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)

struct BIT {
	ll n; vl bit;
	BIT(ll n){
		this->n = n;
		bit.assign(n + 1, 0);
	}
	ll sum(ll r){
		ll ret = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
		return ret;
	}
	ll sum(ll l, ll r){
		return sum(r) - sum(l - 1);
	}
	void upd(ll idx, ll dx){
		for(; idx < n; idx = idx | (idx + 1)) bit[idx] += dx;
	}
};

ll n;

ll solve(vl v1, vl v2){
	vl pos(n); BIT bit(n);
	forn(i, n) pos[v1[i]] = i, bit.upd(i + 1, 1);
	ll ans = 0;
	forn(i, n){
		ans += bit.sum(pos[v2[i]]);
		bit.upd(pos[v2[i]], -1);
	}
	ll res = ans;
	vl pos2(n);
	forn(i, n) pos2[v2[i]] = i;
	rofn(i, n - 1){
		ans += pos2[v1[i]] - (n - 1 - pos2[v1[i]]);
		res = min(res, ans);
	}
	return res;
}

int main(){
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	cin >> n;
	vl a(n), b(n);
	forn(i, n) cin >> a[i], --a[i];
	forn(i, n) cin >> b[i], --b[i];
	cout << min(solve(a, b), solve(b, a)) << endl;
}
