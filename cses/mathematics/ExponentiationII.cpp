/*
 *	NOME: Exponentiation II
 *	LINK: https://cses.fi/problemset/task/1712
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

//Implementation of Modular Binary Exponentiation
ll binpow(ll base, ll exp, ll modulo){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2, modulo);
	if(exp%2 == 1){
		return (((res*res)%modulo)*base) % modulo;
	}else{
		return (res*res)%modulo;
	}
}

int main(){
	int n; cin >> n;
	while(n--){
		ll a, b, c; cin >> a >> b >> c;
		cout << binpow(a, binpow(b, c, MOD-1), MOD) << "\n";
	}
	return 0;
}
