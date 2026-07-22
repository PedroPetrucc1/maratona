/*
 *	NOME: Polygon Area
 *	LINK: https://open.kattis.com/problems/polygonarea
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
		int n; cin >> n;
		if(!n) break;
		vector <pair<double, double>> p(n);
		for(int i=0 ; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}
		p.push_back(make_pair(p[0].first, p[0].second));
		double area = 0;
		for(int i=0; i < n; i++){
			area += (p[i].first*p[i+1].second - p[i].second*p[i+1].first);
		}
		
		if(area < 0) cout << "CW ";
		else if(area > 0) cout << "CCW ";
		
		cout << fixed << setprecision(1);
		cout << abs(area)/2 << '\n'; 
	}
	return 0;
}
