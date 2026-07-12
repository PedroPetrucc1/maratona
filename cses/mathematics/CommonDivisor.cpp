/*
 *	NOME: Common Divisors
 *	LINK: https://cses.fi/problemset/task/1081
*/

#include <bits/stdc++.h>

using namespace std;

int gdc(int a, int b){
	if(b == 0) return a;
	else return gdc(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n; cin >> n;
    vector <long long> num(n);
    for(auto &v : num) cin >> v;
    
    vector <long long> freq(1e6+1, 0);
    for(int i=0; i < n; i++) freq[num[i]] += 1;
 
    for(int i=1e6; i >= 1; i--){
    	long long cont = 0;
    	for(int j=i; j <= 1e6; j += i){
    		cont += freq[j];
    		if(cont >= 2) {cout << i << endl; return 0;}		
    	}
    }

	return 0;
}
