/*
 *	NOME: Hourglass
 *	LINK: https://codeforces.com/problemset/problem/2184/B
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    
    while(t--){
    	int s, k, m; cin >> s >> k >> m;
    	int virada = m/k, tempoatual;
    	
    	if(virada%2 == 0)tempoatual = s;
    	else tempoatual = min(k, s);
    	
    	int tempo = tempoatual - (m%k);
    	if(tempo < 0) cout << 0 << endl;
    	else cout << tempo << endl;
    }
    
	return 0;
}
