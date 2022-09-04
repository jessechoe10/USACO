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

const ll P = 2e5 + 3, M = 1e9 + 7;

ll binpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res *= a, res %= M;
		}
		a *= a; a %= M;
		b >>= 1;
	}
	return res;
}

ll get_hash(vl cur){
	ll res = 0;
	forn(i, cur.size()){
		res += (binpow(P, i) * cur[i]);
		res %= M;
	}
	return res;
}

struct Point {
	ll x, y;
};

ll orientation(Point a, Point b, Point c){
	ll cross = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	return (cross > 0) ? 1: 2;
}

ll dist(Point a, Point b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main(){
	freopen("lightsout.in", "r", stdin);
	freopen("lightsout.out", "w", stdout);
	ll n; cin >> n;
	vector<Point> points(n);
	forn(i, n){
		cin >> points[i].x >> points[i].y;
	}
	vl d(n), angle(n), cw(n), ccw(n);
	forn(i, n){
		d[i] = dist(points[i], points[(i + 1) % n]);
		angle[(i + 1) % n] = orientation(points[i], points[(i + 1) % n], points[(i + 2) % n]);
	}
	FOR(i, 1, n){
		ccw[i] = ccw[i - 1] + d[i - 1];
	}
	cw[n - 1] = d[n - 1];
	rofn(i, n - 2){
		cw[i] = cw[i + 1] +  d[i];
	}
	unordered_map<ll, ll> mpD, mpA;
	FOR(i, 1, n){
		vl curD, curA;
		FOR(j, i, n){
			curD.pb(d[j]);
			curA.pb(angle[j]);
			mpD[get_hash(curD)]++, mpA[get_hash(curA)]++;
		}
	}
	ll ans = 0;
	FOR(i, 1, n){
		vl curD, curA;
		ll sum = 0; bool found = false;
		FOR(j, i, n){
			curD.pb(d[j]);
			curA.pb(angle[j]);
			sum += d[j];
			if(mpD[get_hash(curD)] <= 1 || mpA[get_hash(curA)] <= 1){
				ans = max(ans, sum + min(cw[j + 1], ccw[j + 1]) - min(cw[i], ccw[i]));
				found = true;
				break;
			}
		}
		if(!found){
			ans = max(ans, sum - min(cw[i], ccw[i]));
		}
	}
	cout << ans << endl;
}