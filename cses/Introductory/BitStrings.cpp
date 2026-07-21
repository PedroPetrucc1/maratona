/*
 *	NOME: Bit Strings
 *	LINK: https://cses.fi/problemset/task/1617
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1) return (((res*res)%MOD)*base)%MOD;
	else return (res*res)%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    cout << binpow(2, n) << '\n';
	return 0;
}
