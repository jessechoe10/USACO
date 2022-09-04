#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 18;

ll adj[MAXN], dp[(1 << MAXN)], n, q;

ll bitmask(vl cur){
	vl dp_cur(1 << cur.size()); dp_cur[0] = 1;
	forn(i, (1 << cur.size())){
		ll cow = __builtin_popcount(i);
		forn(j, cur.size()){
			if(!(i & (1 << j))){
				if(cur[cow] & (1 << j)){
					dp_cur[i ^ (1 << j)] += dp_cur[i];
				}
			}
		}
	}
	return dp_cur[(1 << cur.size()) - 1];
}

ll solve(ll query){
	if(dp[query]) return dp[query];
	vl bits; forn(i, n) if(query & (1 << i)) bits.pb(i);
	vl curAdj(bits.size());
	forn(i, bits.size()){
		forn(j, bits.size()){
			if(adj[bits[i]] & (1 << bits[j])) curAdj[i] ^= (1 << j);
		}
	}
	return dp[query] = bitmask(curAdj);
}

int main(){
	cin >> n;
	forn(i, n){
		vl a(n); ll pos = -1;
		forn(j, n){
			cin >> a[j]; --a[j];
			if(a[j] == i) pos = j;
		}
		forn(j, pos + 1){
			adj[i] |= (1 << a[j]);
		}
	}
	cin >> q;
	forn(i, q){
		string breeds; cin >> breeds;
		ll hol = 0, gurn = 0;
		forn(j, n){
			if(breeds[j] == 'H') hol ^= (1 << j);
			else gurn ^= (1 << j);
		}
		cout << solve(hol) * solve(gurn) << endl;
	}
}