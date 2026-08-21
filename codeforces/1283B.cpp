/*
 *	NOME: Candies Division
 *	LINK: https://codeforces.com/problemset/problem/1283/B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		ll candies = 0;
		candies += (n/k)*k;
		
		if(n%k >= k/2) candies += k/2;
		else candies += n%k;
		
		cout << candies << '\n';
	}
}
