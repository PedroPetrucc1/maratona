/*
 *	NOME: Next Prime
 *	LINK: https://cses.fi/problemset/task/3396
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

using u64 = uint64_t; //inteiro de 64 bits
using u128 = __uint128_t; //inteiro de 128 bits

u64 binpow(u64 base, u64 exp, u64 mod){
	if(exp == 0) return 1;
	u128 res = binpow(base, exp/2, mod);
	if(exp%2 == 1){
		return (((res*res)%mod)*base)%mod;
	}else{
		return (res*res)%mod;
	}
}

bool check_composite(u64 p, u64 a, u64 d, int s){ //verifica se o numero é composto
	u64 x = binpow(a, d, p);
	if(x == 1 || x == p-1) return false;
	for(int r = 1; r < s;r++){
		x = (u128)x*x % p;
		if(x == p-1) return false;
	}
	return true;
}

bool MillerRabin(u64 p, int iter = 5){ //implementacao do teste de primalidade de Miller Rabin
	if(p < 4) return p == 2 || p == 3;
	
	int s = 0;
	u64 d = p-1;
	while((d & 1) == 0){ //while para descobrir o valor de s que implica na equacao p - 1 = 2^s * d
		d >>= 1; //equivalente a fazer d /= 2, so que é mais eficiente
		s++;
	}
	
	for(int i=0; i < iter; i++){
		int a = 2+rand() % (p-3); // o rand sorteia um numrero aleatorio ate 2e31 
		if(check_composite(p, a, d, s)) return false;
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;cin >> t;
	
	while(t--){
		ll n; cin >> n;
		while(true){
			n++;
			for(int i = 2; i <= 100; i++){ //teste rapido de primalidade pois 88% dos numeros compostos tem um fator primo menor que 100
				if(n == i) break;
				if(n%i == 0) goto naoprimo;
			}
			
			if(MillerRabin(n)){
				cout << n << '\n';
				break;
			}
			naoprimo:;
		}
	}
	return 0;
}
