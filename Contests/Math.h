struct Math {
	ll MOD, MAXN; vl fact, ifact;
	Math(){
		this -> MOD = 1e9 + 7;
		this -> MAXN = 2e5;
	}
	Math(ll MOD, ll MAXN){
		this -> MOD = MOD;
		this -> MAXN = MAXN;
	}
	ll ceil(ll a, ll b){
		return (a + b - 1) / b;
	}
	ll add(ll a, ll b){
		return (a + b) % MOD;
	}
	ll mult(ll a, ll b){
		return ((a % MOD) * (b % MOD)) % MOD;
	}
	ll sub(ll a, ll b){
		return (a - b + MOD) % MOD;
	}
	ll pow(ll a, ll b){
		ll cur = 1;
		while(b){
			if(b & 1) cur *= a, cur %= MOD;
			a *= a, a %= MOD, b >>= 1;
		}
		return cur;
	}
	ll div(ll a, ll b){
		return mult(a, pow(b, MOD - 2));
	}
	void genFact(){
		fact.pb(1); ifact.pb(1);
		FOR(i, 1, MAXN + 1){ 
			fact.pb(mult(fact.back(), i));
			ifact.pb(pow(fact[i], MOD - 2));
		}
	}
	ll factorial(ll n){
		return fact[n];
	}
	ll choose(ll a, ll b){
		return mult(mult(ifact[b], ifact[a - b]), fact[a]);
	}
	ll gcd(ll a, ll b){
		return __gcd(a, b);
	}
	ll lcm(ll a, ll b){
		return (a * b) / gcd(a, b);
	}
};
