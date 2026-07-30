/*
 *	NOME: 
 *	LINK: 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double h, l; cin >> h >> l;
        cout << fixed << setprecision(12) << (long double)(l*l-h*h)/(2*h) << '\n';
	return 0;
}
