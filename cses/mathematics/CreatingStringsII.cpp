/*
 *	NOME: Creating Strings II
 *	LINK: https://cses.fi/problemset/task/1715
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll MOD = 1e9+7;

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1){
		return (((res*res)%MOD)*base)%MOD;
	}else{
		return (res*res)%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	
	vector <int> freq(26, 0);
	for(char c : s) freq[c - 'a']++;
		
	vector <ll> fat(1e6+1);
	fat[0] = 1;
	ll count = 1;
	while(count <= 1e6){fat[count] = (count * fat[count-1])%MOD; count++;}
	
	
	ll cima = fat[s.size()];
	ll baixo = 1;
	for(int i=0; i < 26; i++){
		if(freq[i] > 1) baixo = (baixo * fat[freq[i]])%MOD;
	}
	
	cout << (cima * (binpow(baixo, MOD-2)))%MOD << '\n';
	return 0;
}
