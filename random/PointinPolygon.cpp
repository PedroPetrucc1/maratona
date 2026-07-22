/*
 *	NOME: Point in Polygon
 *	LINK: https://open.kattis.com/problems/pointinpolygon
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool collinear(pair<ll,ll> p, pair<ll,ll> p1, pair<ll,ll> p2){
	ll a = min(p1.first, p2.first);
	ll b = max(p1.first, p2.first);
	ll x = min(p1.second, p2.second);
	ll y = max(p1.second, p2.second);
	
	return (((p.second - p1.second)*(p2.first - p1.first) == (p.first-p1.first) * (p2.second - p1.second)) && a <= p.first	&& 
		p.first <= b && x <= p.second && p.second <= y);
}

ll intersect(pair<ll,ll> p, pair<ll,ll> p1, pair<ll,ll> p2){
	return ((p1.first-p.first)*(p2.second - p.second) - (p2.first-p.first)*(p1.second-p.second));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
    	int n; cin >> n;
    	
    	if(!n) break;
    	
    	vector <pair<ll, ll>> polygon(n);
    	for(auto &v : polygon) cin >> v.first >> v.second;

		int m; cin >> m;
		while(m--){
    		ll x, y; cin >> x >> y;
    		
   			int intersection = 0;
   			bool flag = false;
   			for(int i=0; i < n; i++){
   				int j = (i+1)%n;
   				if(collinear(make_pair(x, y), polygon[i], polygon[j])){
   					flag = true;
   					break;
   				}
   				
   				if(polygon[i].second <= y && y < polygon[j].second && intersect(make_pair(x, y), polygon[i], polygon[j]) > 0)
   					intersection++;
   				if(polygon[j].second <= y && y < polygon[i].second && intersect(make_pair(x, y), polygon[j], polygon[i]) > 0)
   					intersection++;
   			}
   			
   			if(flag) cout << "on\n";
   			else cout << (intersection%2 == 1 ? "in\n" : "out\n");
   		}
   	}
	return 0;
}
