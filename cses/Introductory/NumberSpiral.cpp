/*
 *	NOME: Number Spiral
 *	LINK: https://cses.fi/problemset/task/1071
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	ll x, y; cin >> y >> x;
    	ll n = max(y, x), m = min(y, x);
    	if(x%2 == y%2){
    		if((m%2 == 1 && y > x) || (m%2 == 0 && x > y)) cout << (n-1)*(n-1)+m << '\n';
    		else cout << n*n-m+1 << '\n';
    	}else{
    		if((m%2 == 1 && y < x) || (m%2 == 0 && x < y)) cout << (n-1)*(n-1)+m << '\n';
    		else cout << n*n-m+1 << '\n';
    	}
    }
	return 0;
}
