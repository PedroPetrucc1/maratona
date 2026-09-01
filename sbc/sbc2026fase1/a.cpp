/*
 * NOME: High Frequency
 * LINK: https://codeforces.com/gym/106679/problem/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector <double> v(n+1, 0), c(n+1, 0);
	for(int i=1; i <= n; i++){
		double a,b; cin >> a >> b;
		c[i] = c[i-1] + a;
		v[i] = v[i-1] + b;
	}
	
	int q; cin >> q;
	while(q--){
		int m; cin >> m;
		double I = (c[m]-v[m])/(c[m]+v[m]);
		if(I > 0) cout << "COMPRA\n";
		else if(I < 0) cout << "VENDA\n";
		else cout << "NEUTRO\n";
		
		//cout << c[m] << " " << v[m] << endl;
	}
	return 0;
}
