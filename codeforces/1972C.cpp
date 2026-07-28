/*
 *	NOME: Permutation Counting
 *	LINK: https://codeforces.com/problemset/problem/1972/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
    	ll n, k; cin >> n >> k;
    	vector <ll> num(n);
    	for(auto &v : num) cin >> v;
    	
    	sort(num.begin(), num.end());
    	ll menorvalor = num[0];
    	ll iguais = 1;
    	
    	for(int i=1 ; i <n ;i++){
    		ll dif = num[i] - num[i-1];
    		ll custo = iguais*dif;
    		
    		if(k >= custo){
    			k -= custo;
    			menorvalor = num[i];
    			iguais++;
    		}else{
    			menorvalor += k/iguais;
    			k %= iguais;
    			break;
    		}
    	}
    	
    	if (k > 0 && iguais == n) {
        	menorvalor += k / n;
        	k %= n;
    	}
    	 	
    	ll total = menorvalor*n - (n-1);
    	
    	ll maiores = n - iguais;
    	
		cout << total + maiores + k << '\n';
    }
    
 
	return 0;
}
