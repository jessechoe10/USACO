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

const ll MAXN = 2000, MOD = 1e9 + 7;

ll dp[MAXN + 1][MAXN + 1][2];

string transform(string s){
	string res = "";
	forn(i, s.length()){
		if(s[i] == '0') res.clear();
		else if(s[i] == '1') continue;
		if(s[i] == '+') res += s[i];
		else res += '2';
	}
	return res;
}

void solve(){
	ll n; cin >> n;
	string a, b; cin >> a >> b;
	string bessie = transform(a), elsie = transform(b);
	forn(i, n + 1) forn(j, n + 1) forn(k, 2) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	forn(i, bessie.length() + 1){
		forn(j, elsie.length() + 1){
			forn(k, 2){
				dp[i][j + 1][1] += dp[i][j][k];
				if(k){
					if(j && elsie[j - 1] != bessie[i]){
						dp[i + 1][j][0] += dp[i][j][k];
					}
				} else {
					dp[i + 1][j][0] += dp[i][j][k];
				}
				dp[i][j + 1][1] %= MOD;
				dp[i + 1][j][0] %= MOD;
			}
		}
	}
	cout << (dp[bessie.length()][elsie.length()][0] + dp[bessie.length()][elsie.length()][1]) % MOD << endl;
}

int main(){
	ll t; cin >> t;
	forn(i, t){
		solve();
	}
}