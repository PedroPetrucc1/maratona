/*
 *	NOME: Two Knights
 *	LINK: https://cses.fi/problemset/task/1072
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    for(ll i =1; i <= n; i++){
    	cout << (i*i*(i*i-1))/2 - 4*(i-2)*(i-1) << '\n';
    }
	return 0;
}
