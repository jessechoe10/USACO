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

const ll MAXN = 20, INF = 1e9;

ll cnt[26][26], dp[(1 << MAXN)];

int main(){
	string s; cin >> s;
	ll n = s.length();
	set<ll> chars; chars.insert(s[0] - 'a');
	FOR(i, 1, n){
		cnt[s[i] - 'a'][s[i - 1] - 'a']++;
		chars.insert(s[i] - 'a');
	}
	vl letters;
	for(auto& letter: chars){ 
		letters.pb(letter);
	}
	n = letters.size();
	FOR(i, 1, (1 << n)) dp[i] = INF;
	dp[0] = 1;
	forn(i, (1 << n)){
		forn(j, n){
			if(!(i & (1 << j))){
				ll res = 0;
				forn(k, n){
					if(!(i & (1 << k))){
						res += cnt[letters[j]][letters[k]];
					}
				}
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + res);
			}
		}
	}
	ll res = dp[(1 << n) - 1];
	cout << res << endl;
}