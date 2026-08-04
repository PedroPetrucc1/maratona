/*
 *	NOME: Attention to the Meeting
 *	LINK: https://codeforces.com/gym/105327/problem/A
*/
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    k -= (n-1);
    cout << k/n << '\n';
	return 0;
}
