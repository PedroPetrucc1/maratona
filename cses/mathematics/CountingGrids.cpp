/*
 *	NOME: Counting Grids
 *	LINK: https://cses.fi/problemset/task/2210
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll MOD = 1e9+7;


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
   	
   	ll n; cin >> n;
   	ll nenhuma = binpow(2, n*n);
   	ll duas = binpow(2, (n*n+1)/2);
   	ll umaetres = n%2 == 0 ? (2*binpow(2, n*n/4))%MOD : (2*binpow(2, n*n/4+1))%MOD;
   	
   	cout << ((nenhuma+duas+umaetres)*binpow(4, MOD-2))%MOD << '\n'; 
	return 0;
}
