/*
 *	NOME: Polygon Lattice Points
 *	LINK: https://cses.fi/problemset/task/2193
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    
    vector <pair<ll,ll>> poly(n);
    for(auto &v : poly) cin >> v.first >> v.second;
    poly.push_back(make_pair(poly[0].first, poly[0].second));
    
    ll area = 0;
    for(int i=0; i < n; i++){
    	area += poly[i].first*poly[i+1].second - poly[i].second*poly[i+1].first; 
    }
    
    area = abs(area);
    area /= 2;
    
    ll latticeboundary = 0;
    for(int i=0; i < n; i++){
    	ll g = gcd(abs(poly[i].first-poly[i+1].first), abs(poly[i].second-poly[i+1].second));
    	latticeboundary += g;
    }
    
    cout << area - latticeboundary/2 + 1 << " " << latticeboundary << '\n';
    
	return 0;
}
