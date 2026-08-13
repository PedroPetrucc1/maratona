/*
 *	NOME: Maximum Manhattan Distances
 *	LINK: https://cses.fi/problemset/task/3410
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    ll maxU, maxV, minU, minV;
    minU = minV = 2e9;
    maxU = maxV = -2e9;
    
    while(n--){
    	ll x, y; cin >> x >> y;
    	ll u = x+y, v = x-y;
    	
    	maxU = max(maxU, u);
    	minU = min(minU, u);
    	maxV = max(maxV, v);
    	minV = min(minV, v);
    	
    	cout << max(maxU-minU, maxV-minV) << '\n';
    }
	return 0;
}
