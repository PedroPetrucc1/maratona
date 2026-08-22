/*
 * NOME: Maximum Sum
 * LINK: https://codeforces.com/problemset/problem/1946/B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		ll totalsum = 0;
		vector <ll> num(n), dp(n, 0);
		for(int i=0; i < n; i++){
			cin >> num[i];
			totalsum = (totalsum + num[i])%MOD;
		}
		
		dp[0] = num[0];
		ll maxsum = dp[0];
		for(int i=1; i < n; i++){
			dp[i] = max(num[i], dp[i-1]+num[i]);
			maxsum = max(maxsum, dp[i]);
		}
		
		if(maxsum < 0) maxsum = 0;
		
		ll ganho = 0;
        ll atualmax = maxsum%MOD;
        for(int i = 0; i < k; i++) {
            ganho = (ganho+atualmax)%MOD;
            atualmax = (atualmax*2)%MOD;
        }
		cout << (totalsum+ganho+2*MOD)%MOD << '\n';
	}
}
