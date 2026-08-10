/*
 *	NOME: Fibonacci Numbers
 *	LINK: https://cses.fi/problemset/task/1722
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

vector <ll> fib(ll n){
	if(n==0) return {0, 1};
	
	vector <ll> res = fib(n/2);	
	
	ll fk = (res[0]*((2*res[1] - res[0] + MOD)%MOD))%MOD;
	ll fk1 = ((res[0]*res[0])%MOD + (res[1]*res[1])%MOD)%MOD;
	
	if(n%2 == 0) return {fk, fk1};
	else return {fk1, (fk+fk1)%MOD};
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector <ll> ans = fib(n);
	cout << ans[0] << '\n';
}
