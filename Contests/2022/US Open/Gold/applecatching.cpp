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

typedef pair<pl, pl> P;

const ll INF = 1e9;

bool cmp(P a, P b){
	if((a.f.s - a.s.f) == (b.f.s - b.s.f)){
		return (a.f.s + a.s.f) < (b.f.s + b.s.f);
	} else {
		return (a.f.s - a.s.f) < (b.f.s - b.s.f);
	}
}

int main(){
	ll n; cin >> n;
	vector<P> events(n);
	forn(i, n){
		cin >> events[i].f.f >> events[i].f.s >> events[i].s.f >> events[i].s.s;
	}
	sort(all(events), cmp);
	multiset<pl> ms;
	ll ans = 0;
	forn(i, n){
		if(events[i].f.f == 1){
			ms.insert({events[i].f.s + events[i].s.f, events[i].s.s});
		} else {
			pl top = {events[i].f.s + events[i].s.f, INF};
			auto it = ms.upper_bound(top);
			if(it == ms.begin()) continue;
			--it; ll cur = events[i].s.s, cnt = 0;
			while(!ms.empty()){
				pl x = *it; ll take = min(x.s, cur);
				x.s -= take, cur -= take, cnt += take;
				ms.erase(it);
				if(x.s){
					ms.insert({x.f, x.s});
				}
				if(cur == 0){
					break;
				}
				it = ms.upper_bound(top);
				if(it == ms.begin()){
					break;
				}
				it--;
			}
			ans += cnt;
		}
	}
	cout << ans << endl;
}
