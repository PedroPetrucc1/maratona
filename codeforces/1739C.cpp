/*
 *	NOME: Card Game
 *	LINK: https://codeforces.com/problemset/problem/1739/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 998244353;
vector <ll> fat(1e6+1);

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1){
		return (((res*res)%MOD)*base)%MOD;
	}else{
		return (res*res)%MOD;
	}
}

ll comb(int n, int r){
	if(r < 0 || r > n) return 0;
	ll cima = fat[n];
	ll baixo = (fat[r] * fat[n-r]) % MOD;
	return (cima * binpow(baixo, MOD-2)) % MOD;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	fat[0] = 1;
	int cont = 1;
	while(cont <= 1e6){ fat[cont] = (fat[cont-1]*cont)%MOD; cont++;}
	
	ll a[70], b[70];
	a[2] = 1;
	b[2] = 0;
	
	for(int i=4; i <= 60; i+= 2){
		a[i] = (comb(i-1, i/2-1) + b[i-2])%MOD;
		b[i] = (comb(i, i/2) - a[i] - 1 + 2*MOD)%MOD;
	}
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << a[n] << " " << b[n] << " " << 1 << '\n';
	}
	return 0;
}
