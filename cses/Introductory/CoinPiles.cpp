/*
 *	NOME: Coin Piles
 *	LINK: https://cses.fi/problemset/task/1754
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
    	ll a, b; cin >> a >> b;
    	if((2*a-b)%3 != 0 || (2*a - b) < 0 || (2*b - a)%3 != 0 || (2*b  - a) < 0) cout << "NO\n";
    	else cout << "YES\n";
    }
	return 0;
}
