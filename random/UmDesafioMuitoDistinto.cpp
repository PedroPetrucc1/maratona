/*
 *	NOME: Um Desafio Muito Distinto
 *	LINK: https://neps.academy/br/exercise/3268
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll checar(ll i, ll f){
	return ((i+f)*(f-i+1))/2LL;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int p;cin >> p;
    while(p--){
		ll a, b, l;
    	cin >> l >> a >> b;
    	if(checar(a, b) < l) cout << (b - a + 1) << '\n';
    	else{
			ll inicio = a, fim = b;
			while(inicio < fim){
				ll meio = (inicio+fim)/2;
				
				if(checar(a, meio) >= l)fim = meio;
				else inicio = meio+1;
			}
			
			cout << inicio - a + 1 << '\n';
		}
	}
	return 0;
}
