#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(ll i = a; i >= b; i--)
#define pb push_back

const ll MOD = 1e9 + 7, MAXN = 1e5;
const string BASES = "ATGC";

ll dp[MAXN][4][4][4];

int main(){
	string s; cin >> s;
	forn(n, 4){
		forn(l, 4){
			if(s[0] == '?' || s[0] == BASES[l]){
				dp[0][n][l][l] = 1;
			}
		}
	}
	FOR(i, 1, s.length()){
		forn(m2, 4){
			if(s[i] == '?' || s[i] == BASES[m2]){
				forn(n, 4){
					forn(l, 4){
						forn(m, 4){
							if(m != m2){
								dp[i][n][l][m2] += dp[i - 1][n][l][m];
								dp[i][n][l][m2] %= MOD;
							}
							if(n == m){
								dp[i][l][m2][m2] += dp[i - 1][n][l][m];
								dp[i][l][m2][m2] %= MOD;
							}
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	forn(m, 4){
		forn(l, 4){
			ans += dp[s.length() - 1][m][l][m];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}
