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
 
ll pairs1[18][18], pairs2[18][18];
 
int main(){
   string s; cin >> s;
   string t; cin >> t;
   vl count1(18), count2(18);
   forn(i, s.length()){
       ll cur = s[i] - 'a';
       forn(j, 18){
           pairs1[cur][j] += count1[j];
       }
       count1[cur]++;
   }
   forn(i, t.length()){
       ll cur = t[i] - 'a';
       forn(j, 18){
           pairs2[cur][j] += count2[j];
       }
       count2[cur]++;
   }
   ll q; cin >> q;
   forn(i, q){
       string query; cin >> query;
       bool works = true;
       forn(i, query.length()){
           for(ll j = i; j < query.length(); j++){
               char c1 = query[i] - 'a', c2 = query[j] - 'a';
               if((pairs1[c1][c2] != pairs2[c1][c2]) || (pairs1[c2][c1] != pairs2[c2][c1])){
                   works = false;
               }
           }
       }
       if(works){
           cout << "Y";
       } else {
           cout << "N";
       }
   }
   cout << endl;
}
