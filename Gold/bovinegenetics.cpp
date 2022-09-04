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

const ll MAXN = 1e5, MOD = 1e9 + 7;

ll dp[MAXN][4][4][4];

int main(){
	string s; cin >> s;
	map<char, ll> mp;
	mp['A'] = 0, mp['T'] = 1, mp['G'] = 2, mp['C'] = 3, mp['?'] = 4;
	ll n = s.length();
	forn(l, 4){
		forn(r, 4){
			if(s[0] == '?' || mp[s[0]] == r){
				dp[0][l][r][r] = 1;
			}
		}
	}
	FOR(i, 1, n){
		forn(r2, 4){
			if(s[i] == '?' || mp[s[i]] == r2){
				forn(l1, 4){
					forn(l2, 4){
						forn(r1, 4){
							if(r1 != r2){
								dp[i][l1][l2][r2] += dp[i - 1][l1][l2][r1];
								dp[i][l1][l2][r2] %= MOD;
							}
							if(l1 == r1){
								dp[i][l2][r2][r2] += dp[i - 1][l1][l2][r1];
								dp[i][l2][r2][r2] %= MOD;
							}
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	forn(l1, 4){
		forn(l2, 4){
			ans += dp[n - 1][l1][l2][l1];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}