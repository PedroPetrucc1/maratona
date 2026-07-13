/*
 *	NOME: Divisor Analysis
 *	LINK: https://cses.fi/problemset/task/2182
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

vector <ll> basen;
vector <ll> expn;


ll binpow(ll base, ll exp, ll mod){
    if(exp == 0) return 1;
    ll res = binpow(base, exp / 2, mod);
    if(exp % 2 == 1){
        return (((res * res) % mod) * (base % mod)) % mod;
    } else {
        return (res * res) % mod;
    }
}

ll NumDivisor(ll n){
	ll numdivisors = 1;
	for(int i=0; i < n; i++){
		numdivisors = (numdivisors * (expn[i]+1))%MOD;
	}
	return numdivisors;
}

ll SumDivisor(ll n){
	ll total = 1;
	for(int i=0; i < n; i++){
		ll p  = basen[i], x = expn[i];

		ll numerator = (binpow(p, x+1, MOD)-1)%MOD;
		ll denominator = binpow(p-1, MOD-2, MOD); //calcula inverso modular de p-1
		
		ll pw = (numerator * denominator)%MOD;
		
		total = (total * pw)%MOD;
	}
	
	return total;
}

ll ProductDivisor(ll n){
	ll total = 1;
	ll div_count = 1;
	ll MOD_PHI = MOD-1; //modulo especial para exponentes por conta do pequeno teorema de fermat
	
	for(int i=0; i < n; i++){
		ll p = basen[i], x = expn[i];
		
		ll term1 = binpow(total, x+1, MOD);
		
		ll powerp = (x * (x+1) / 2) % MOD_PHI; // calculo do expoente entao usamos MOD_PHI
		powerp = (powerp * div_count) % MOD_PHI;
		
		ll term2 = binpow(p, powerp, MOD);
		
		total = (term1 * term2) % MOD;
		
		div_count = (div_count * (x+1)) % MOD_PHI; //como div_count é usado como expoente (parte do powerp) usamos MOD_PHI
	}
	
	return total;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    
    for(int i =0; i < n; i++){
    	ll a, b; cin >> a >> b;
    	basen.push_back(a);
    	expn.push_back(b);
    }
    
    cout << NumDivisor(n) << " " << SumDivisor(n) << " " << ProductDivisor(n) << '\n';
	return 0;
}
