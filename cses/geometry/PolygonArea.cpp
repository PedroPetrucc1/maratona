/*
 *	NOME: Polygon Area
 *	LINK: https://cses.fi/problemset/task/2191
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector <pair<ll, ll>> p(n);
    for(auto &v : p) cin >> v.first >> v.second;
    p.push_back(make_pair(p[0].first, p[0].second));
    
    ll area = 0;
    for(int i = 0; i < n; i++){
    	area += (p[i].first*p[i+1].second - p[i].second*p[i+1].first);
    }
    
    //para calcular a area real fazemos area /= 2 mas para
    // garantir que é inteiro os exercicios geralmente pedem 2*area
    	
    	cout << abs(area) << '\n';
	return 0;
}
