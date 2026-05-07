/*
 * LINK: https://cses.fi/problemset/task/1635
 * NOME: Coin Combinations I
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main(){
	int n, x; cin >> n >> x;
	int coins[n];
	vector<int>dp(x+1, 0);
	dp[0] = 1; //caso base
	for(int i=0; i < n; i++) cin >> coins[i];
	
	for(int i=1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i - coins[j] >= 0){
				dp[i] = (dp[i] + dp[i - coins[j]])%MOD;
			}
		}
	}
	
	cout << dp[x];
}
