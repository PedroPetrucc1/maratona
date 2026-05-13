/*
 * LINK: https://cses.fi/problemset/task/1158
 * NOME: Book Shop
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x; cin >> n >> x;
	vector <int> book(n);
	vector <int> price(n);
	for(int i=0; i < n; i++){cin >> book[i];}
	for(int i=0; i < n; i++){cin >> price[i];}
	
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	
	for(int i=1; i <= n; i++){
    	for(int j=0; j <= x; j++){
            if(j >= book[i-1]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-book[i-1]] + price[i-1]);
            }else{
                dp[i][j] = max(dp[i-1][j], 0);
            }
        }
    }

	cout << dp[n][x];
}
