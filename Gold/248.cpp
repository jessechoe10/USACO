#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 248;

ll dp[MAXN][MAXN];

int main(){
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	ll n; cin >> n;
	forn(i, n){
		cin >> dp[i][i];
	}
	ll res = 0;
	for(ll len = 2; len <= n; len++){
		forn(i, n - len + 1){
			ll j = i + len - 1;
			for(ll k = i; k < j; k++){
				if(dp[i][k] == dp[k + 1][j]){
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;
}