/*
 *	NOME: Exponentiation
 *	LINK: https://cses.fi/problemset/task/1095
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

//Implementation of Binary Exponentiation
ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1){
		return (((res*res)%MOD)*base) % MOD;
	}else{
		return (res*res)%MOD;
	}
}

int main(){
	int n; cin >> n;
	while(n--){
		ll a, b; cin >> a >> b;
		cout << binpow(a, b) << "\n";
	}
	return 0;
}
