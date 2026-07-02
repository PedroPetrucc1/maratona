/*
 *	NOME: After party in Campinas
 *	LINK: https://codeforces.com/gym/106598/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

int song[200100], value[200100], nextpos[200100];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    
    for(int i=1;i<=n;i++) cin >> value[i] >> song[i];
    
    nextpos[n] = n+1;
    for(int i=n-1; i >= 1; i--){
    	if(song[i+1] != song[i]) nextpos[i] = i+1;
    	else nextpos[i] = nextpos[i+1];
    }
       
    for(int i=0; i < q; i++){
    	int d, o;
    	cin >> d >> o;
    	int li = 1, hi = n+1;
    	while(li < hi){
    		int mid = li + (hi-li)/2;
    		if(value[mid] > d) li = mid+1;
    		else hi = mid;
    	}
    	int pos = li;
    	
    	if(song[pos] == o) pos = nextpos[pos];
    	
    	if(pos == n+1) cout << -1 << '\n';
    	else cout << pos << '\n';
    	
    	
    }
	return 0;
}
