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

const ll MAXN = 1e5, INF = 2e9;

vpl bounds; vl adj[MAXN]; ll n, ans;
ll lft[MAXN], rgt[MAXN], vis[MAXN], cnt[MAXN], val[MAXN], best[MAXN];

ll dfs1(ll v, ll x){
	if(vis[v]){
		return lft[v];
	}
	vis[v] = true;
	lft[v] = bounds[v].f - x;
	for(ll u: adj[v]){
		if(!vis[u]){
			lft[v] = max(lft[v], dfs1(u, x));
		}
	}
	return lft[v];
}

ll dfs2(ll v, ll x){
	if(vis[v]){
		return rgt[v];
	}
	vis[v] = true;
	rgt[v] = bounds[v].s + x;
	for(ll u: adj[v]){
		if(!vis[u]){
			rgt[v] = min(rgt[v], dfs2(u, x));
		}
	}
	return rgt[v];
}

bool works(ll x){
	forn(i, n){
		vis[i] = false;
		lft[i] = 0;
	}
	dfs1(0, x);
	forn(i, n){
		vis[i] = false;
		rgt[i] = 0;
	}
	dfs2(0, x);
	forn(i, n){
		if(cnt[i]){
			ll l = max(bounds[i].f, lft[i]), r = min(bounds[i].s, rgt[i]);
			if(l > r) return false;
		}
	}
	return true;
}

void dfs(ll v, ll par){
	val[v] = max(lft[v], bounds[v].f);
	if(par != -1) val[v] = max(val[v], best[par]);
	best[v] = max(best[par], val[v] - ans);
	for(ll u: adj[v]){
		dfs(u, v);
	}
}

void solve(ll b){
	cin >> n;
	bounds.clear();
	forn(i, n) adj[i].clear(), cnt[i] = 0, val[i] = 0, best[i] = 0;
	vl p(n); forn(i, n - 1) cin >> p[i], --p[i];
	forn(i, n){
		ll l, r; cin >> l >> r;
		bounds.pb({l, r});
	}
	forn(i, n - 1){
		adj[p[i]].pb(i + 1);
		cnt[p[i]]++;
	}
	ll l = 0, r = 1e9; ans = 1e9;
	while(l <= r){
		ll m = l + (r - l) / 2;
		if(works(m)){
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << ans << endl;
	if(b){
		works(ans);
		dfs(0, -1);
		forn(i, n){
			cout << val[i];
			if(i < n - 1) cout << " ";
		}
		cout << endl;
	}
}

int main(){
	ll t, b; cin >> t >> b;
	forn(i, t){
		solve(b);
	}
}