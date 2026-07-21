/*
 *	NOME: Two Sets
 *	LINK: https://cses.fi/problemset/task/1092
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll total = (1+n)*n/2;
    if(total%2 == 1) cout << "NO\n";
    else{
    	cout << "YES\n";
    	vector <int> set1, set2;
    	vector <bool> visited(n+1, false);
    	total /= 2;
    	ll sumset1 = 0, maxelement = n;
    	while(sumset1 < total){
    		ll somaremaning = total - sumset1;
    		if(somaremaning > maxelement){
    			set1.push_back(maxelement);
    			visited[maxelement] = true;
    			sumset1 += maxelement;
    			maxelement--;
    		}else{
    			set1.push_back(somaremaning);
    			visited[somaremaning] = true;
    			sumset1 = total;
    		}
    	}
    	
    	for(int i=1; i <= n; i++){
    		if(!visited[i]) set2.push_back(i);
    	}
    	
    	cout << set1.size() << "\n";
        for (auto k : set1) {
            cout << k << " ";
        }

        cout << '\n' << set2.size() << "\n";
        for (auto k : set2) {
            cout << k << " ";
        }
    }
	return 0;
}
