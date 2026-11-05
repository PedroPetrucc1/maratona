//Link: https://codeforces.com/gym/106800/problem/G

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k; cin >> n >> k;
	
	int v = k/3, e = k%3;
	while(2*v+e != n-1){
		if(v == 0){
			cout << -1 << endl;
			return 0;
		}
		v-= 1, e+=3; 
	}
	
	vector <pair<pair<int, int>, set <int>>> vs(n+1, {{v, e}, {}});
	
	int countv = 0, counte = 0;
	for(int i=1; i <= n; i++){
		for(int k=1; k <= n; k++){
			if(countv == v && counte == e) {countv = 0; counte = 0;  break;}
			if(vs[i].first.first != 0 && k != i && countv != v && !vs[k].second.count(i)){
				cout << i << " > " << k << endl;
				vs[i].first.first--;
				countv++;
				vs[k].second.insert(i);
				vs[i].second.insert(k);	
			}else if(vs[i].first.second != 0 && vs[k].first.second != 0 && k != i && counte != e && !vs[k].second.count(i)){
				cout << i << " = " << k << endl;
				vs[i].first.second--;
				vs[k].first.second--;
				counte++;
				vs[k].second.insert(i);
				vs[i].second.insert(k);
			}
		}
		countv = counte = 0;
	}
	return 0;
}
