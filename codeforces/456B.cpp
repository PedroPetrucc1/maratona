/*
 *	NOME: Fedya and Maths
 *	LINK: https://codeforces.com/problemset/problem/456/B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll ans = binpow(base, exp/2);
	if(exp%2 == 1) return (((ans*ans)%5)*base)%5;
	else return (ans*ans)%5;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int len = s.size(), n=0;
    if(len == 1)n = s[0] - '0';	
    else n = (s[len-2]-'0')*10 + s[len-1]-'0';
    
    cout << (1 + binpow(2, n) + binpow(3, n) + binpow(4, n))%5 << '\n';
	return 0;
}
