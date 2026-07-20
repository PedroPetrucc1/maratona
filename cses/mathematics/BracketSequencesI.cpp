/*
 *	NOME: Bracket Sequences I
 *	LINK: https://cses.fi/problemset/task/2064
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll MAX = 1e6;
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
    int n; cin >> n;
    if(n%2 == 1){
    	cout << 0 << '\n';
    	return 0;
    }
    
    n /= 2;
	vector <ll> fat(1e6+1);
	fat[0] = 1;
	int cont = 1;
	while(cont <= 1e6){ fat[cont] = (fat[cont-1]*cont)%MOD; cont++;}

	ll cima = fat[2*n], baixo = (fat[n]*fat[n])%MOD;
	ll inversobaixo = binpow(baixo, MOD-2);
	cout << (((cima*inversobaixo)%MOD)*binpow((n+1), MOD-2))%MOD << '\n';
	
	return 0;
}
