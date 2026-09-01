/*
 * NOME: Contingency
 * LINK: https://codeforces.com/gym/106679/problem/K
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector <ll> c(n), k(n);
	ll ans = 0, difmin = 1e15, indice = 0;
	for(auto &v : c) cin >> v;
	for(int i=0; i < n; i++){
		cin >> k[i];
		if(k[i] > c[i]){
			cout << -1 << '\n';
			return 0;
		}
		difmin = min(difmin, c[i]-k[i]);
		ans += c[i];
	}
	
	
	cout << ans	- difmin << '\n';
	return 0;
}
