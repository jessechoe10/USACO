#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define f first
#define s second

int main(){
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	vl ps(n + 1);
	forn(i, n){
		if(s[i] == 'H'){
			ps[i + 1] = ps[i] + 1;
		} else {
			ps[i + 1] = ps[i] - 1;
		}
	}
	multiset<pl> st; st.insert({0, 0});
	vl dp(n + 1);
	FOR(i, 1, n + 1){
		pl best = *st.begin();
		dp[i] = best.f + (best.s >= ps[i]);
		st.insert({dp[i], ps[i]});
		if(st.size() > k){
			st.erase(st.find({dp[i - k], ps[i - k]}));
		}
	}
	cout << dp[n] << endl;
}
