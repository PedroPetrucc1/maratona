/*
 * LINK: https://cses.fi/problemset/task/1636
 * NOME: Coin Combinations II
*/

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7; 

int main(){
	int n,x; cin >> n >> x;
	vector <long long> coins(n);
	long long dp[1000001] = {0};
	for(int i=0; i < n; i++)cin >> coins[i];
	
	dp[0] = 1; //caso base
	
	for(int i=0; i < n; i++){
		for(int j=0; j <= x; j++){
			if(j >= coins[i]){
				dp[j] = (dp[j] + dp[j - coins[i]])%MOD;
			}
		}
	}
	
	cout << dp[x];
}
