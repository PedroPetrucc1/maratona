/*
 * NOME: Arpa’s hard exam and Mehrdad’s naive cheat
 * LINK: https://codeforces.com/problemset/problem/742/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	if(n == 0) cout << 1 << '\n';
	else{
		n %= 4;
		
		if(n == 1) cout << 8 << '\n';
		else if(n == 2) cout << 4 << '\n';
		else if(n == 3)cout << 2 << '\n';
		else cout << 6 << '\n';
	}
}
