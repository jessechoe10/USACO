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

const ll MAXN = 1e5;

vl adj[MAXN], cycle;
bool vis[MAXN];
set<pl> s[MAXN];
map<ll, ll> mp;
ll occ;

void ins(ll pos, ll k){
	for(auto& a: s[pos]){
		if(a.s > k) continue;
		if(!mp[a.f]){
			occ++;
		}
		mp[a.f]++;
	}
}

void rem(ll pos, ll k){
	for(auto& a: s[pos]){
		if(a.s > k) continue;
		if(mp[a.f] == 1){
			occ--;
		}
		mp[a.f]--;
	}
}

void dfs(ll v){
	if(vis[v]){
		return;
	}
	vis[v] = true;
	cycle.pb(v);
	for(ll u: adj[v]){
		dfs(u);
	}
}

int main(){
	ll n, k, m; cin >> n >> k >> m;
	vl pos(n); forn(i, n) pos[i] = i, s[i].insert({i, 0});
	// Simulate the swaps
	forn(i, k){
		ll a, b; cin >> a >> b; --a, --b;
		s[pos[a]].insert({b, i + 1}); s[pos[b]].insert({a, i + 1});
		swap(pos[a], pos[b]);
	}
	forn(i, n){
		adj[pos[i]].pb(i);
	}
	vl res(n);
	forn(i, n){
		if(!vis[i]){
			dfs(i);
			ll cycles = m / k, extra = m % k;
			// Initiate our sliding window
			if(cycles >= cycle.size()){
				cycles = cycle.size();
				extra = 0;
			}
			ll l = 0, r = cycles - 1;
			forn(j, cycles){
				ins(cycle[j], k);
			}
			for(; l < cycle.size(); l++){
				r++; r %= cycle.size();
				ins(cycle[r], extra);
				res[cycle[l]] = occ;
				rem(cycle[r], extra);
				rem(cycle[l], k);
				ins(cycle[r], k);
			}
			occ = 0;
			mp.clear();
			cycle.clear();
		}
	}
	forn(i, n){
		cout << res[i] << endl;
	}
}