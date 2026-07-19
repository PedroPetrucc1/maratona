/*
 *	NOME: Distributing Apples
 *	LINK: https://cses.fi/problemset/task/1716
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
	
	int n, m; cin >> n >> m;
		
	vector <ll> fat(2*1e6+1);
	fat[0] = 1;
	ll count = 1;
	while(count <= 2*1e6){fat[count] = (count * fat[count-1])%MOD; count++;}
	
	ll cima = fat[n+m-1];
	ll baixo = (fat[m]*fat[n-1])%MOD;
	cout << (cima * (binpow(baixo, MOD-2)))%MOD << '\n';
	return 0;
}
