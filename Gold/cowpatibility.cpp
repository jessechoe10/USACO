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

struct Flavors {
	int id[5];
};

bool operator< (const Flavors &a, const Flavors &b){
	forn(i, 5){
		if(a.id[i] < b.id[i]) return true;
		if(a.id[i] > b.id[i]) return false;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);

	ll n; cin >> n;
	map<Flavors, int> mp;
	ll ans = 0;
	forn(i, n){
		int flavors[5];
		forn(i, 5) cin >> flavors[i];
		sort(flavors, flavors + 5);
		FOR(j, 1, 32){
			Flavors f; int cnt = 0;
			forn(k, 5){
				f.id[k] = 0;
			}
			forn(k, 5){
				if(j & (1 << k)){
					f.id[cnt++] = flavors[k];
				}
			}
			if(cnt & 1){
				ans += mp[f];
			} else {
				ans -= mp[f];
			}
			mp[f]++;
		}
	}
	cout << (n * (n - 1) / 2) - ans << endl;
}