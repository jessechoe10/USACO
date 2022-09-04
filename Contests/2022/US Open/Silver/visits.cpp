#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
 
#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define f first
#define s second
 
const ll MAXN = 1e5;
 
vl adj1[MAXN], adj2[MAXN];
bool vis[MAXN];
stack<ll> s;
vl cycle;
 
void dfs1(ll v){
   vis[v] = true;
   for(ll u: adj1[v]){
       if(!vis[u]){
           dfs1(u);
       }
   }
   s.push(v);
}
 
void dfs2(ll v){
   vis[v] = true;
   cycle.pb(v);
   for(ll u: adj2[v]){
       if(!vis[u]){
           dfs2(u);
       }
   }
}
 
int main(){
   ll n; cin >> n;
   vl v(n);
   forn(i, n){
       ll a; cin >> a >> v[i];
       adj1[i].pb(a - 1);
       adj2[a - 1].pb(i);
   }
   forn(i, n){
       if(!vis[i]){
           dfs1(i);
       }
   }
   forn(i, n){
       vis[i] = false;
   }
   ll ans = 0;
   while(!s.empty()){
       ll cur = s.top(); s.pop();
       if(!vis[cur]){
           cycle.clear();
           dfs2(cur);
           if(cycle.size() == 1){
               ans += v[cycle[0]];
           } else {
               ll sumEdge = 0, minEdge = 1e9;
               forn(i, cycle.size()){
                   minEdge = min(minEdge, v[cycle[i]]);
                   sumEdge += v[cycle[i]];
               }
               ans += sumEdge - minEdge;
           }
       }
   }
   cout << ans << endl;
}
