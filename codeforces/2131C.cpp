/*
 *	NOME: Make it Equal
 *	LINK: https://codeforces.com/contest/2131/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long l;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	l n, k, ver = 0; cin >> n >> k;
    	multiset <l> S, T;
    	
    	for(int i=0; i < n; i++){
    		l x; cin >> x;
    		S.insert(min(x%k, k-(x%k)));
    	}
    	
    	for(int i=0; i < n; i++){
    		l x; cin >> x;
    		T.insert(min(x%k, k-(x%k)));
    	}
    	
    	if(S == T) cout << "YES" << '\n';
    	else cout << "NO" << '\n';
    }
    
	return 0;
}
