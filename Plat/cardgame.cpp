#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)

int main(){
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	ll n; cin >> n;
	set<ll> s; forn(i, 2 * n) s.insert(i + 1);
	vl elsie(n); forn(i, n) cin >> elsie[i], s.erase(elsie[i]);
	vl ans(n + 1);
	set<ll> tmp = s;
	FOR(i, 1, n + 1){
		auto it = s.lower_bound(elsie[i - 1]);
		if(it != s.end()){
			s.erase(it);
		}
		ans[i] += n - s.size();
	}
	s = tmp;
	rofn(i, n){
		auto it = s.lower_bound(elsie[i]);
		if(it != s.begin()){
			s.erase(--it);
		}
		ans[i] += n - s.size();
	}
	ll res = 0;
	forn(i, n + 1){
		res = max(res, ans[i]);
	}
	cout << res << endl;
}
