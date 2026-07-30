/*
 *	NOME: Come Together
 *	LINK: https://codeforces.com/problemset/problem/1845/B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
    	int cell = 0;
    	int xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;
    	cout << (dist(xa, ya, xb, yb) + dist(xa, ya, xc, yc) - dist(xb, yb, xc, yc))/2 + 1 << '\n';
    }
	return 0;
}
