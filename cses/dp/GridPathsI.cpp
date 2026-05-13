/*
 * LINK: https://cses.fi/problemset/task/1638
 * NOME: Grid Paths I
*/

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

int main(){
	int n; cin >> n;
	vector<vector<long long>> dp(n, vector<long long>(n, 1)); //tudo com 1 ja engloba o caso base de dp[0][i] e dp[i][0]
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			char c; cin >> c;
			if(c == '*'){
				dp[i][j]= 0;
				if(i==0){
					for(int k=j; k < n; k++){dp[0][k] = 0;}
				}else if(j == 0){
					for(int k=i; k < n; k++){dp[k][0] = 0;}
				}
			}
			
		}
	}
	
	if(dp[0][0] == 0){cout << 0;return 0;} //caso especial
	
	for(int i=1; i < n; i++){
		for(int j=1; j < n; j++){
			if(dp[i][j] != 0) dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}

	cout << dp[n-1][n-1];
}
