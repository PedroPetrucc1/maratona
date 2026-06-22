/*
 *	NOME: Metro Ticket
 *	LINK: https://codeforces.com/gym/106598/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, c, k; cin >> n >> c >> k;
	long days[n];
	for(int i=0; i < n;i++) cin >> days[i];
	long ct = c+k;
	
	for(int i=1; i < n; i++){
		ct += min((days[i]-days[i-1])*c, c+k);
	}
	cout << ct << endl;
	return 0;
}
