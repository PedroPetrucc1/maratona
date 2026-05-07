/*
 * LINK: https://cses.fi/problemset/task/1634
 * NOME: Minimizing Coins
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6+7;
int main(){
	int n, x;
	cin >> n >> x;
	int coins[n];
	vector <int> dp(x+1, INF);
	
	for(int i=0; i <n; i++) cin >> coins[i];
	dp[0]=0;
	for(int i=0; i < n; i++){
		for(int j=coins[i]; j <= x; j++){
			dp[j]= min(dp[j], dp[j-coins[i]]+1);
		}
	}
	
	if(dp[x] == INF){
		cout << -1 << endl;
	}else{
		cout << dp[x] << endl;
	}	
}
