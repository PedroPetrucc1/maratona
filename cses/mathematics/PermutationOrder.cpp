/*
 *	NOME: Permutation Order
 *	LINK: https://cses.fi/problemset/task/3397
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector <ll> fat(21);
	fat[0] = 1; fat[1] = 1;
	for(ll i=1; i <= 20; i++) fat[i] = i*fat[i-1];

	int t; cin >> t;
	while(t--){
		int op; cin >> op;
		if(op == 1){
			ll n, k; cin >> n >> k;
			k--;
			vector <int> num(20);
			for(int i=1; i <= 20; i++) num[i] = i;
			vector <int> ans;
			for(int i=1; i <= n; i++){
				ll grupo = k/fat[n-i];
				ans.push_back(num[grupo]);
				num.erase(num.begin()+grupo);
				k %= fat[n-i];
			}
			
			for(int k : ans) cout << k+1 << " ";
			cout << '\n';
		}else{
			int n; cin >> n;
			vector <int> p(n);
			for(int i=0;i < n; i++) cin >> p[i];
			
			ll total = 0;
			vector <int> num(20);
			for(int i=0; i < 20; i++) num[i] = i+1;
			
			for(int i=0; i < n; i++){
				auto it =  find(num.begin(), num.end(), p[i]);
				int pos = distance(num.begin(), it);
				total += pos * fat[n-i-1];
				num.erase(num.begin()+pos);
			}
			
			cout << total+1 << '\n';
		}
	}
	
	return 0;
}
