/*
 *	NOME: João João
 *	LINK: https://codeforces.com/gym/106073/problem/J
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n[4] = {1, 1, 1, 1};
    for(int i=0; i < 10; i++){
    	int a; cin >> a;
    	n[a-1] = 0;
    }
    int sum = 0;
    for(int k : n) sum += k;
    cout << sum;
	return 0;
}
