#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 1e5;

vl adj[MAXN], subt[MAXN];
ll len[MAXN], n;

void dfs(ll cur, ll par){
	len[cur] = 1;
	for(ll u: adj[cur]){
		if(u != par){
			dfs(u, cur);
			len[cur] += len[u];
			subt[cur].pb(len[u]);
		}
	}
	if(len[cur] != n) subt[cur].pb(n - len[cur]);
}

bool ok(ll k){
	vl cnt(k);
	forn(i, n){
		ll cur = 0;
		for(ll u: subt[i]){
			ll z = u % k; if(z == 0) continue;
			if(cnt[k - z]) cnt[k - z]--, cur--;
			else cnt[z]++, cur++;
		}
		if(cur) return false;
	}
	return true;
}

int main(){
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	cin >> n;
	forn(i, n - 1){
		ll a, b; cin >> a >> b;
		--a, --b; adj[a].pb(b), adj[b].pb(a);
	}
	dfs(0, -1);
	FOR(i, 1, n){
		if((n - 1) % i) cout << 0;
		else cout << ok(i);
	}
	cout << endl;
}
