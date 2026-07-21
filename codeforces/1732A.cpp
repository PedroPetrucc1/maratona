/*
 *	NOME: Bestie
 *	LINK: https://codeforces.com/problemset/problem/1732/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int gcd(int a, int b){
	if(b==0)return a;
	else return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
   	while(t--){
   		int n; cin >> n;
   		int cost = 0, g = 0;
   		int a[n+1];
   		for(int i=1; i <= n; i++){
   			cin >> a[i];
   			g = gcd(g, a[i]);
   		}
   		
   		if(g == 1) cout << 0 << '\n';
   		else if(gcd(g, n) == 1) cout << 1 << '\n';
   		else  if(gcd(g, n-1) == 1) cout << 2 << '\n';
   		else cout << 3 << '\n';
   	}
	return 0;
}
