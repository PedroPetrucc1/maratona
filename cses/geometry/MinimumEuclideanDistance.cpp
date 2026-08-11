/*
 *	NOME: Minimum Euclidean Distance
 *	LINK: https://cses.fi/problemset/task/2194
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXV = 7*1e18;
vector <pair<ll, ll>> p;
    
ll euclideanDist(pair<ll,ll> p1, pair<ll,ll> p2){
	return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}

ll closestPair(int esq, int dir){
	int d = dir-esq;
	if(d == 0) return MAXV;
	else if(d == 1) return euclideanDist(p[esq], p[dir]);
	int meio = d/2 + esq;
	ll xMeio = p[meio].first;
	
	ll melhor  = min(closestPair(esq, meio),closestPair(meio+1, dir));
	
	vector <pair<ll, ll>> faixa;
	for(int i=esq; i <= dir; i++){
		if((p[i].first - xMeio) * (p[i].first - xMeio) < melhor){
			faixa.push_back(p[i]);
		}
	}
	
	sort(faixa.begin(), faixa.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
		return a.second < b.second;
	});
	
	int tamanho = faixa.size();
	for(int i=0; i < tamanho; i++){
		for(int j= i+1; j < tamanho; j++){
			if((faixa[j].second - faixa[i].second)*(faixa[j].second-faixa[i].second) >= melhor) break;
			melhor = min(melhor, euclideanDist(faixa[i], faixa[j]));
		}
	}
	
	return melhor;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for(int i=0; i < n; i++){ll x, y; cin >> x >> y; p.push_back(make_pair(x, y));}
    sort(p.begin(), p.end());
    
    cout << closestPair(0, n-1) << '\n';
    
	return 0;
}
