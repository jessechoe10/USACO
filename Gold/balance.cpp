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

int main(){
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	ll n; cin >> n;
	stack<ll> s; queue<ll> q;
	vl a(2 * n), ps(2 * n);
	forn(i, 2 * n) cin >> a[i];
	ll l = 0, r = 0, ones = 0;
	ps[0] = a[0];
	forn(i, n){
		if(!a[i]) l += ones;
		else s.push(i), ++ones;
	}
	ones = 0;
	FOR(i, n, 2 * n){
		ps[i] = ps[i - 1];
		if(!a[i]) q.push(i), r += ones;
		else ++ones, ps[i]++;
	}
	FOR(i, 1, n){
		ps[i] = ps[i - 1] + a[i];
	}
	// Move from left to right
	ll curL = l, curR = r, ans = abs(r - l), curSwaps = 0, cnt = 0;
	while(!s.empty() && !q.empty()){
		curL -= (n - s.top() - 1);
		curL += (ps[s.top()] - 1);
		curSwaps += (q.front() - s.top());
		curR += (q.size() - (ps[q.front()] + cnt) - 1);
		ans = min(ans, curSwaps + abs(curR - curL));
		cnt++;
		s.pop(); q.pop();
	}
	// Reset stuff
	while(!s.empty()) s.pop();
	while(!q.empty()) q.pop();
	ps.assign(2 * n, 0);
	curL = l, curR = r, curSwaps = 0, cnt = 0;
	ROF(i, 2 * n - 1, n){
		ps[i] = ps[i + 1] + (a[i] == 0);
	}
	FOR(i, n, 2 * n){
		if(a[i]) q.push(i);
	}
	ps[0] = a[0];
	FOR(i, 1, n){ 
		ps[i] = ps[i - 1] + a[i];
		if(!a[i]) s.push(i);
	}
	while(!s.empty() && !q.empty()){
		curR -= ps[q.front()];
		curSwaps += (q.front() - s.top());
		curL -= ps[s.top()];
		ans = min(ans, curSwaps + abs(curR - curL));
		s.pop(); q.pop();
	}
	cout << ans << endl;
}