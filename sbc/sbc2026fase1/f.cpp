/*
 * NOME: Flower
 * LINK: https://codeforces.com/gym/106679/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector <int> f(1e7+2);
	
	f[1] = 2, f[2] = 3;
	
	for(int i=1; i <= 1e7; i++){
		if(f[i] == 0) f[i] = f[i-1]+1;
		if(f[i] <= 1e7) f[f[i]] = 3*i;
		
	}
	
	int n; cin >> n;
	cout << f[n] << '\n';
	
	return 0;
}
