/*
 *	NOME: Christmas Party
 *	LINK: https://cses.fi/problemset/task/1717
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	
	vector<ll> chaotic(n+1);
    chaotic[1] = 0;
    chaotic[2] = 1;
    for(int i = 3; i <= n; i++){
        chaotic[i] = ((i-1)*(chaotic[i-2] + chaotic[i-1]))%MOD;
    }
    cout << count[n] << "\n";
    
	return 0;
}
