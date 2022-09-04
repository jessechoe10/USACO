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

typedef array<ll, 3> Tri;

vpl points;

ll cross(pl a, pl b, pl c){
	b.f -= a.f, b.s -= a.s;
	c.f -= a.f, c.s -= a.s;
	return b.f * c.s - b.s * c.f;	
}

ll area(Tri t){
	return abs(cross(points[t[0]], points[t[1]], points[t[2]]));
}

bool inside(Tri a, ll b){
	ll sum = 0;
	forn(i, 3){
		swap(a[i], b);
		sum += area(a);
		swap(a[i], b);
	}
	sum -= area(a);
	return (sum == 0);
}

bool cmp(Tri a, Tri b){
	return area(a) < area(b);
}

const ll MAXN = 40, MOD = 1e9 + 7;

ll dp[MAXN][MAXN][MAXN][MAXN + 1];

int main(){
	ll n; cin >> n;
	forn(i, n){
		ll x, y; cin >> x >> y;
		points.pb({x, y});
	}
	vector<Tri> tri;
	forn(i, n){
		FOR(j, i + 1, n){
			FOR(k, j + 1, n){
				tri.pb({i, j, k});
			}
		}
	}
	sort(all(tri), cmp);
	ll ans = 0;
	for(Tri t: tri){
		ll in = 0;
		vector<Tri> next;
		forn(i, n){
			if(inside(t, i)){
				in++;
			} else {
				forn(j, 3){
					Tri cur = t; cur[j] = i;
					sor(cur);
					if(inside(cur, t[j])) next.pb(cur);
				}
			}
		}
		in -= 3; assert(in >= 0);
		dp[t[0]][t[1]][t[2]][0] = 1;
		forn(i, in + 1){
			if(i < in){
				dp[t[0]][t[1]][t[2]][i + 1] += dp[t[0]][t[1]][t[2]][i] * (in - i);
				dp[t[0]][t[1]][t[2]][i + 1] %= MOD;
			}
			for(Tri u: next){
				dp[u[0]][u[1]][u[2]][i + 1] += dp[t[0]][t[1]][t[2]][i];
				dp[u[0]][u[1]][u[2]][i + 1] %= MOD;
			}
		}
		if(in == n - 3){
			ans += dp[t[0]][t[1]][t[2]][in];
			ans %= MOD;
		}
	}
	cout << (ans * 6) % MOD << endl;
}