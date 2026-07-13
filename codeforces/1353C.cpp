/*
 *	NOME: Board Moves
 *	LINK: https://codeforces.com/problemset/problem/1353/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    
    while(t--){
    	ll n; cin >> n;
    	ll sum = 0;
    	for(int i=0; i < n-1; i++) sum += (n-i)*(n-i-1);
    	cout << sum << '\n';
    }
    
	return 0;
}
