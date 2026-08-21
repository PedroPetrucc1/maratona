/*
 * NOME: Paint the Array
 * LINK: https://codeforces.com/problemset/problem/1618/C
*/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	int n, passou; cin >> n;
    	vector <ll> num(n);
    	for(auto &v : num) cin >> v;
    	
		ll gcdpar = 0, gcdimpar = 0;
		
		for(int i=0; i < n; i++){
			if(i%2 == 0) gcdpar = gcd(gcdpar, num[i]);
			else gcdimpar = gcd(gcdimpar, num[i]);
		}
		
		int verpar = 1, verimpar = 1;
		for(int i=1; i < n; i+= 2){
			if(num[i]%gcdpar == 0){
				verpar = 0;
				break;
			}
		}
		
		if(verpar){
			cout << gcdpar << '\n';
			continue;
		}
		
		for(int i=0; i < n; i+= 2){
			if(num[i]%gcdimpar == 0){
				verimpar = 0;
				break;
			}
		}
		
		if(verimpar){
			cout << gcdimpar << '\n';
			continue;
		}
		
		cout << 0 << '\n';
    }
}
