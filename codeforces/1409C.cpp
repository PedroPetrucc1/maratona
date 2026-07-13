/*
 *	NOME: Yet Another Array Restoration
 *	LINK: https://codeforces.com/problemset/problem/1409/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	int n, x, y; cin >> n >> x >> y;
    	int bestmax = 1e9;
    	vector <int> bestans;
    	for(int i=1; i <= y-x; i++){
    		if((y-x)%i != 0) continue;
    		
    		if((y-x)/i + 1 > n) continue;
    		
    		int start = min(n-1, (y-1)/i);
    		int val = y - start*i;
    		
    		vector <int> ans;
    		for(int j=0; j < n; j++) ans.push_back(val + i*j);
    		
    		int ansmax = ans.back();
    		
    		if(bestmax > ansmax){
    			bestmax = ansmax;
    			bestans = ans;
    		}
    	}
    	
    	for(int val : bestans){
    		cout << val << " ";
    	}
    	cout << '\n';
    	
    }
    
	return 0;
}
