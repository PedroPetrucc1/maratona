/*
 *	NOME: Trailing Zeros
 *	LINK: https://cses.fi/problemset/task/1618
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
   	ll total = 0;
   	for(ll i =5; i <= 1e9; i *= 5) total += n/i;
   	cout << total << '\n';
	return 0;
}
