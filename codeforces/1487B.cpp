/*
 *	NOME: Cat Cycle
 *	LINK: https://codeforces.com/problemset/problem/1487/B
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
    	k-= 1;
    	if(n%2 == 0){
    		cout << k%n + 1 << endl;
    	}else{
    		cout << (k + (k/(n/2)) )%n +1 << endl;
    	}
    }
    
	return 0;
}
