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

const ll MAXN = 1000;

ll dp[MAXN + 1][MAXN + 1];

int main(){
	ll t, k; cin >> t >> k; t--;
	forn(i, t + 1){
		forn(j, min(i + 1, t + 1)){
			if(j == 0 || i == j){
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	double sum = 0;
	vector<double> prob;
	forn(i, t + 1){
		double top = dp[t][i], bottom = pow(2, t);
		prob.pb(top / bottom);
	}
	double ev = 0;
	forn(i, k){
		double cur = 0;
		forn(i, t + 1){
			cur += max(ev, (double) i) * prob[i];
		}
		ev = cur;
	}
	cout << fixed << setprecision(7) << ev + 1 << endl;
}