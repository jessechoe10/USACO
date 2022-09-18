#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

const ll MAXN = 200;

char grid[MAXN][MAXN];
ll psum[MAXN][MAXN];

int main(){
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	ll n, m; cin >> n >> m;
	forn(i, n){
		forn(j, m){
			cin >> grid[i][j];
		}
	}
	forn(j, m){
		psum[0][j] = (grid[0][j] == 'X');
		FOR(i, 1, n){
			psum[i][j] = psum[i - 1][j] + (grid[i][j] == 'X');
		}
	}
	ll ans = 0;
	forn(top, n){
		FOR(bottom, top, n){
			ll i = 0, j = 0;
			while(j < m){
				while(grid[top][j] == '.' && grid[bottom][j] == '.' && j < m){
					if(top){
						if((psum[bottom][j] - psum[top - 1][j] == 0) && (psum[bottom][i] - psum[top - 1][i] == 0)){
							ans = max(ans, (bottom - top + 1) * (j - i + 1));
						} else if((psum[bottom][i] - psum[top - 1][i] > 0)){
							i++;
						}
					} else {
						if(psum[bottom][j] == 0 && psum[bottom][i] == 0){
							ans = max(ans, (bottom + 1) * (j - i + 1));
						} else if(psum[bottom][i] > 0){
							i++;
						}
					}
					j++;
				}
				i = j; j++;
			}
		}
	}
	cout << ans << endl;
}
