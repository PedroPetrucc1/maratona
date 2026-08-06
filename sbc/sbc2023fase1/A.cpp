/*
 *	NOME: Amusement Park Adventure
 *	LINK: https://codeforces.com/gym/104555/problem/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h, total = 0; cin >> n >> h;
    while(n--){
    	int a; cin >> a;
    	if(a <= h) total++;
    }
    cout << total <<'\n';
	return 0;
}
