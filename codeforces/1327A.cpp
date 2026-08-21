/*
 * NOME: Sum of Odd Integers
 * LINK: https://codeforces.com/problemset/problem/1327/A
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
    
		if(k*k > n) cout << "NO\n";
    	else if(n%2 == k%2) cout << "YES\n";
    	else cout << "NO\n";
    }
}
