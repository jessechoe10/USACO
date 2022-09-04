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
 
int main(){
   string s; cin >> s;
   ll q; cin >> q;
   ll n = s.length();
   vl c(n + 1), o(n + 1), w(n + 1);
   forn(i, n){
       c[i + 1] += c[i];
       o[i + 1] += o[i];
       w[i + 1] += w[i];
       if(s[i] == 'C'){
           c[i + 1]++;
       } else if(s[i] == 'O'){
           o[i + 1]++;
       } else {
           w[i + 1]++;
       }
   }
   forn(i, q){
       ll l, r; cin >> l >> r;
       ll sumC = c[r] - c[l - 1], sumO = o[r] - o[l - 1], sumW = w[r] - w[l - 1];
       ll ow = min(sumO, sumW), cons = max(sumO, sumW) - ow;
       if((sumC + ow + cons) & 1){
           if(cons % 2 == 0){
               cout << "Y";
           } else {
               cout << "N";
           }
       } else {
           cout << "N";
       }
   }
   cout << endl;
}
