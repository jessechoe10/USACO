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

int main(){
	ll n; cin >> n;
	vl a(n), res(n + 1), hi(n, -1), hilo(n);
	forn(i, n){
		ll x; cin >> x;
		a[--x] = i;
	}
	stack<ll> st; st.push(-1);
	rofn(i, n - 1){
		while(a[i] < st.top()){
			st.pop();
		}
		hi[a[i]] = st.top();
		st.push(a[i]);
	}
	while(st.size() != 1) st.pop();
	ll ans = 0; cout << ans << endl;
	forn(i, n){
		while(st.top() > a[i]){
			ans -= hilo[st.top()];
			st.pop();
		}
		if((hi[a[i]] != -1) && (st.top() == -1 || hi[st.top()] != hi[a[i]])){
			hilo[a[i]]++;
		}
		ans += hilo[a[i]];
		st.push(a[i]);
		cout << ans << endl;
	}
}