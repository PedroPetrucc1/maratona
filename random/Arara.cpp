/*
 *	NOME: Arara!
 *	LINK: https://neps.academy/br/exercise/3262
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    cout << (5*(n-1)+1 <= m ? "S\n" : "N\n");
	return 0;
}
