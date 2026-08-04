/*
 *	NOME: Fractions are better when continued
 *	LINK: https://codeforces.com/gym/105327/problem/F
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector <int> a(42), b(42);
	a[1] = 1;
	b[1] = 2;
	for(int i=2; i <= 40; i++){
		a[i] = b[i-1];
		b[i] = a[i-1]+b[i-1];
	}
	
	int n; cin >> n;
	cout << a[n] << '\n';
	return 0;
}
