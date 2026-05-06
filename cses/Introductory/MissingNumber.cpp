/*
 * LINK: https://cses.fi/problemset/task/1083
 * NOME: Missing Number
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, a; cin >> n;
	long max_sum = 0, sum = 0;
	max_sum = ((1+n)*n)/2;
	for(int i=0; i < n-1; i++){
		cin >> a;
		sum += a;
	}
	cout << max_sum - sum;
	return 0;
}
