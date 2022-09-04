#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rofn(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))

const ll MAXN = 1000, INF = 1e9;

typedef pair<pl, ll> T;

char grid[MAXN][MAXN];
ll rockDist[MAXN][MAXN], repl[MAXN][MAXN], n, d;
bool vis[MAXN][MAXN];
vpl robots[MAXN * MAXN];

vl dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

bool canMove(ll x, ll y){
	return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#';
}

int main(){
	cin >> n >> d;
	queue<pl> rockQ; queue<pl> robotQ;
	forn(i, n){
		forn(j, n){
			cin >> grid[i][j];
			rockDist[i][j] = INF;
			repl[i][j] = INF;
			if(grid[i][j] == '#'){
				rockQ.push({i, j});
				rockDist[i][j] = 0;
			}
			if(grid[i][j] == 'S'){
				robotQ.push({i, j});
				repl[i][j] = 0;
			}
		}
	}
	while(!rockQ.empty()){
		pl cur = rockQ.front(); rockQ.pop();
		forn(i, 4){
			ll x = cur.f + dx[i], y = cur.s + dy[i];
			if(!canMove(x, y)) continue;
			if(rockDist[cur.f][cur.s] + 1 < rockDist[x][y]){
				rockDist[x][y] = rockDist[cur.f][cur.s] + 1;
				rockQ.push({x, y});
			}
		}
	}
	while(!robotQ.empty()){
		pl cur = robotQ.front(); robotQ.pop();
		robots[rockDist[cur.f][cur.s] - 1].pb(cur);
		vis[cur.f][cur.s] = true;
		if(repl[cur.f][cur.s] >= rockDist[cur.f][cur.s] * d) continue;
		forn(i, 4){
			ll x = cur.f + dx[i], y = cur.s + dy[i];
			if(!canMove(x, y)) continue;
			if((repl[cur.f][cur.s] + 1) > rockDist[x][y] * d) continue;
			if(repl[cur.f][cur.s] + 1 < repl[x][y]){
				repl[x][y] = repl[cur.f][cur.s] + 1;
				robotQ.push({x, y});
			}
		}
	}
	queue<pl> q;
	rofn(i, n * n - 1){
		queue<pl> curQ;
		while(!q.empty()){
			curQ.push(q.front()); q.pop();
		}
		while(!curQ.empty()){
			pl cur = curQ.front(); curQ.pop();
			forn(k, 4){
				ll x = cur.f + dx[k], y = cur.s + dy[k];
				if(!canMove(x, y) || vis[x][y]) continue;
				vis[x][y] = true;
				q.push({x, y});
			}
		}
		for(pl robot: robots[i]){
			q.push(robot);
		}
	}
	ll ans = 0;
	forn(i, n){
		forn(j, n){
			ans += vis[i][j];
		}
	}
	cout << ans << endl;
}