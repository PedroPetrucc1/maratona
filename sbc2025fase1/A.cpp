/*
 *	NOME: A healthy menu
 *	LINK: https://codeforces.com/gym/106073/problem/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
   	ll c[n][m];
    
    for(int i=0; i < n; i++)
    	for(int j=0; j < m; j++)
    		cin >> c[i][j];
    		
    ll turma = 0;
    ll maximo;
    for(int i=0; i < m; i++){
    	maximo = -1;
    	for(int j=0; j < n; j++){
    		maximo = max(maximo, c[j][i]);
    	}
    	turma += maximo;
    }
    
    cout << turma << '\n';
	return 0;
}
