/*
 * NOME: Exchange Rate
 * LINK: https://codeforces.com/gym/106679/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t, c, k; cin >> t >> c >> k;
	cout << min(t*k, c);
	
	return 0;
}
