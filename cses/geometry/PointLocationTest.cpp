/*
 *	NOME: Point Location Test
 *	LINK: https://cses.fi/problemset/task/2189
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	return (y1-y2)*(x3-x1) - (x1-x2)*(y3-y1);

}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
    	ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    	ll res = collinear(x1, y1, x2, y2, x3, y3);
    	
    	if(res == 0) cout << "TOUCH\n";
    	else if(res < 0) cout << "RIGHT\n";
    	else cout << "LEFT\n";
    }
	return 0;
}
