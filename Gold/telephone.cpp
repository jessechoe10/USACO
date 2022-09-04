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

const ll MAXN = 5e4, MAXK = 50, INF = 1e18;

ll dist[MAXK][MAXN], grid[MAXK][MAXK];
bool vis[MAXK][MAXN];

typedef pair<ll, pl> T;

int main(){
	ll n, k; cin >> n >> k;
	vl b(n);
	forn(i, n){
		cin >> b[i], --b[i];
	}
	forn(i, k){
		forn(j, k){
			char c; cin >> c;
			grid[i][j] = (c == '1');
		}
	}
	forn(i, k) forn(j, n) dist[i][j] = INF;
	dist[b[0]][0] = 0; queue<T> q; q.push({0, {b[0], 0}});
	while(!q.empty()){
		T cur = q.front(); q.pop();
		if(cur.s.s < 0 || cur.s.s >= n) continue;
		if(grid[cur.s.f][b[cur.s.s]]){
			if(cur.s.s - 1 >= 0){
				if(dist[b[cur.s.s]][cur.s.s - 1] == INF){
					dist[b[cur.s.s]][cur.s.s - 1] = cur.f + 1;
					q.push({cur.f + 1, {b[cur.s.s], cur.s.s - 1}});
				}
			}
			if(cur.s.s + 1 < n){
				if(dist[b[cur.s.s]][cur.s.s + 1] == INF){
					dist[b[cur.s.s]][cur.s.s + 1] = cur.f + 1;
					q.push({cur.f + 1, {b[cur.s.s], cur.s.s + 1}});
				}
			}
		}
		if(cur.s.s - 1 >= 0){
			if(dist[cur.s.f][cur.s.s - 1] == INF){
				dist[cur.s.f][cur.s.s - 1] = cur.f + 1;
				q.push({cur.f + 1, {cur.s.f, cur.s.s - 1}});
			}
		}
		if(cur.s.s + 1 < n){
			if(dist[cur.s.f][cur.s.s + 1] == INF){
				dist[cur.s.f][cur.s.s + 1] = cur.f + 1;
				q.push({cur.f + 1, {cur.s.f, cur.s.s + 1}});
			}
		}
	}
	ll ans = INF;
	forn(i, k){
		forn(j, k){
			if(grid[i][j] && j == b[n - 1]){
				ans = min(ans, dist[i][n - 1]);
			}
		}
	}
	(ans == INF) ? cout << -1 << endl : cout << ans << endl;
}