/*
 *	NOME: Enigma of the Jewelry Case
 *	LINK: https://codeforces.com/gym/105327/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int m[n][n];
    for(int i=0; i < n; i++)
    	for(int j=0; j < n; j++)
    		cin >> m[i][j];
    
    if(m[0][0] > m[0][n-1] && m[0][0] < m[n-1][0]) cout << 1 << '\n';
    else if(m[0][0] > m[0][n-1] && m[0][0] > m[n-1][0]) cout << 2 << '\n';
    else if(m[0][0] < m[0][n-1] && m[0][0] > m[n-1][0]) cout << 3 << '\n';
    else cout << 0 << '\n';
    
	return 0;
}
