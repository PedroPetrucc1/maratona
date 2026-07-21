/*
 *	NOME: Counting Necklaces 
 *	LINK: https://cses.fi/problemset/task/2209
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll MOD = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1){
		return (((res*res)%MOD)*base)%MOD;
	}else{
		return (res*res)%MOD;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    
    ll ans = 0;
    for(int i=0; i < n; i++){
    	ll k = gcd(i, n);
    	ans = (ans+(binpow(m, k)*binpow(n, MOD-2))%MOD)%MOD;
    }
    
    cout << ans << '\n';
	return 0;
}
