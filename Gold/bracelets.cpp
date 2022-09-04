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

void solve(){
	ll n, m; cin >> n >> m;
	vector<vl> bracelets(m);
	forn(i, m){
		ll k; cin >> k;
		forn(j, k){
			ll c; cin >> c; c--;
			bracelets[i].pb(c);
		}
	}
	bool works = true;
	// Check 1: Horizontal line sweep
	forn(i, m){
		vl vis(n); stack<ll> s;
		forn(j, bracelets[i].size()){
			if(vis[bracelets[i][j]]){
				if(s.top() != bracelets[i][j]){
					works = false;
				}
				s.pop();
			} else {
				s.push(bracelets[i][j]);
				vis[bracelets[i][j]] = true;
			}
		}
	}
	if(!works){
		cout << "NO" << endl;
		return;
	}
	// Check 2: Make sure each color is continuous
	vl boundL(n, -1), boundR(n, -1);
	forn(i, m){
		forn(j, bracelets[i].size()){
			boundR[bracelets[i][j]] = i;
		}
	}
	rofn(i, m - 1){
		forn(j, bracelets[i].size()){
			boundL[bracelets[i][j]] = i;
		}
	}
	forn(i, n){
		if(boundL[i] == -1) continue;
		for(ll j = boundL[i]; j <= boundR[i]; j++){
			bool found = false;
			forn(k, bracelets[j].size()){
				if(bracelets[j][k] == i){
					found = true;
				}
			}
			if(!found){
				works = false;
				break;
			}
		}
	}
	if(!works){
		cout << "NO" << endl;
		return;
	}
	// Check 3: Check bracelets cutting across
	bool before[n][n];
	forn(i, n) forn(j, n) before[i][j] = false;
	forn(i, m){
		vl l(n, -1), r(n, -1);
		forn(j, bracelets[i].size()){
			l[bracelets[i][j]] = j;
			r[bracelets[i][j]] = j;
		}
		forn(i, n){
			FOR(j, i + 1, n){
				if(l[i] == -1 || l[j] == -1) continue;
				if(r[i] < l[j]){
					if(before[j][i]){
						works = false;
						break;
					}
					before[i][j] = true;
				} else if(r[j] < l[i]){
					if(before[i][j]){
						works = false;
						break;
					}
					before[j][i] = true;
				}
			}
		}
	}
	if(!works){
		cout << "NO" << endl;
		return;
	}
	// Check 4: Are the parents consistent?
	vl par(n, -1);
	forn(i, m){
		vl vis(n); stack<ll> s;
		forn(j, bracelets[i].size()){
			if(vis[bracelets[i][j]]){
				s.pop();
			} else {
				if(!s.empty()){
					if(s.top() != par[bracelets[i][j]] && i != boundL[bracelets[i][j]]){
						works = false;
						break;
					} 
					par[bracelets[i][j]] = s.top();
				} else {
					if(par[bracelets[i][j]] != -1){
						works = false;
						break;
					}
				}
				s.push(bracelets[i][j]);
				vis[bracelets[i][j]] = true;
			}
		}
	}
	if(!works){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
	ll t; cin >> t;
	forn(i, t){
		solve();
	}
}