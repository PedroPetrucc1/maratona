/*
 *	NOME: Sum of Divisors
 *	LINK: https://cses.fi/problemset/task/1082
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

ll sum(ll m){
	ll total = 0;
	ll d = 1;
	while(d <= m){
		ll q = m / d;
		ll d_end = m / q;
		
		ll cnt = d_end - d + 1;   // quantidade de termos
		ll s = d + d_end;          // soma do primeiro + ultimo termo
		
		ll half, other;
		if(cnt % 2 == 0){
			half = cnt / 2;   // divide o par por 2 antes do modulo
			other = s;
		} else {
			half = s / 2;     // se cnt é impar s é garantidamente par
			other = cnt;
		}
		
		ll block = ((half % MOD) * (other % MOD)) % MOD;
		block = (block * (q % MOD)) % MOD;
		
		total = (total + block) % MOD;
		d = d_end + 1; //passa para o proximo bloco
	}
	return total;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;

    cout << sum(n) << '\n';
    
	return 0;
}
