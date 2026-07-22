/*
 *	NOME: Max Points on a Line
 *	LINK: https://leetcode.com/problems/max-points-on-a-line/description/
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    
    vector <vector<int>> p(n, vector<int>(2));
    for(int i=0; i < n; i++) cin >> p[i][0] >> p[i][1];
    
    int globalmax = 0;
    for(int i=0; i < n; i++){
    	map<pair<int,int>, int> freq;
    	int currentmax = 0;
    	for(int j=i+1; j < n ;j++){
    		int dx = p[j][0] - p[i][0];
    		int dy = p[j][1] - p[i][1];
    		
    		int g = gcd(dx, dy);
    		dx /= g;
    		dy /= g;
    		
    		if(dx < 0 || (dx == 0 && dy < 0)){
    			dx = -dx;
    			dy = -dy;
    		}
    		
    		freq[make_pair(dx, dy)]++;
    		currentmax = max(currentmax, freq[make_pair(dx,dy)]);
    	}
    	globalmax = max(globalmax, currentmax+1);
    }
    
    cout << globalmax << '\n';
	return 0;
}
