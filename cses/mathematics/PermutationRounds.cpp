/*
 *	NOME: Permutation Rounds
 *	LINK: https://cses.fi/problemset/task/3398
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int MOD = 1e9+7;

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
    vector <int> num(n+1);
    for(int i=1; i <= n; i++) cin >> num[i];
    
    vector <bool> visitados(n+1, false);
    vector <int> ciclos;
    int current, atual;
    
    for(int i=1; i <= n; i++){
    	current = 0;
    	atual = i;
    	while(!visitados[atual]){
    		visitados[atual] = true;
    		atual = num[atual];
    		current = current+1;
    	}
    	ciclos.push_back(current);
    }
    
    vector <int> ppf(1e6, 0);
	for(int k : ciclos){
		int num = k;
    	for(int i=2; i <= num; i++){
    		if(num%i == 0){
    			int power = 0;
    			while(num%i == 0){
    				power++;
    				num /= i;
    			}
    			ppf[i] = max(ppf[i], power); 
    		}
    	}
    	
    	if(num != 1){
    		ppf[num] = max(1, ppf[num]);
    	}
	}
	
	ll ans = 1;
	for(int i=2; i <= 1e6; i++){
		if(ppf[i] != 0) ans = (ans*binpow(i, ppf[i]))%MOD;
	}
	
	cout << ans << '\n';
	return 0;
}
