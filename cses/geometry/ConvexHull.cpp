/*
 *	NOME: Convex Hull
 *	LINK: https://cses.fi/problemset/task/2195
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int orientation(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
	ll area = a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
	if(area < 0) return -1; //sentido horario
	else if(area > 0) return 1; //sentido anti-horario
	else return 0;
}

void convexhull(vector<pair<ll,ll>>& points){
	int n = points.size();
	if(n <= 2){
		cout << n << '\n';
		for(auto p : points) cout << p.first << " " << p.second << '\n';
		return;
	}
	
	sort(points.begin(), points.end());
	
	vector <pair<ll,ll>> up, down;
	
	for(int i=0; i < n; i++){
		while(down.size() >= 2 && orientation(down[down.size()-2], down.back(), points[i]) < 0){
			down.pop_back();
		}
		
		while(up.size() >= 2 && orientation(up[up.size()-2], up.back(), points[i]) > 0){
			up.pop_back();
		}
		
		down.push_back(points[i]);
		up.push_back(points[i]);
	}
	
	vector<pair<ll,ll>> hull;
	for(int i=0; i < (int)down.size(); i++) hull.push_back(down[i]);
	for(int i= (int)up.size() - 2; i>0; i--) hull.push_back(up[i]);
	
	sort(hull.begin(), hull.end());
	hull.erase(unique(hull.begin(), hull.end()), hull.end());
	
	cout << hull.size() << '\n';
	for(auto p : hull) cout << p.first << " " << p.second << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector <pair<ll, ll>> points(n);
    for(int i=0; i < n; i++) cin >> points[i].first >> points[i].second;
    
    convexhull(points);
    
	return 0;
}
