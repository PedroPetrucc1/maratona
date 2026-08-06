/*
 *	NOME: Fatigue-Fighting Vacation
 *	LINK: https://codeforces.com/gym/104555/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c, r; cin >> n >> c >> r;
    vector <ll> cans(c);
    ll total = r;
    for(auto &v : cans) cin >> v;
    
    while(r--){
    	ll a; cin >> a;
    	n += a;
    }
    
    for(ll k : cans){
    	n -= k;
    	if(n < 0) break;
    	total++;
    }
    
    cout << total << '\n';
    
	return 0;
}
