/*
 * LINK: https://cses.fi/problemset/task/1637
 * NOME: Removing Digits
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6+7;

int main(){
	int n; cin >> n;
	vector <int> dp(n+1, INF);
	
	dp[0] = 0; // caso base
	
	for(int i=1; i <= n; i++){
		for(char c : to_string(i)){
			if((c - 48) > 0){
				dp[i] = min(dp[i], dp[i-(c-48)] + 1);
			}
		}
	}
	
	cout << dp[n];
}
	
