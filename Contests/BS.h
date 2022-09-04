bool works(ll x){
	return true;
}

ll minBS(ll l, ll h){
	ll ans = h;
	while(l <= r){
		ll m = l + (r - l) / 2;
		if(works(m)){
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	} 
	return ans;
}

ll maxBS(ll l, ll h){
	ll ans = l;
	while(l <= r){
		ll m = l + (r - l) / 2;
		if(works(m)){
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}
