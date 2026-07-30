/*
 *	NOME: Triangle
 *	LINK: https://codeforces.com/problemset/problem/6/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tri(int a, int b, int c){
	if(a+b > c && a+c > b  && c+b > a) return 1;
	else if(a+b == c || a+c == b || c+b == a) return 0;
	else return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    if(tri(a, b, d) > 0 || tri(a, b, c) > 0|| tri(b, c, d) > 0 || tri(a, d, c) > 0) cout << "TRIANGLE\n";
    else if(tri(a, b, d) == 0 || tri(a, b, c) == 0|| tri(b, c, d) == 0 || tri(a, d, c) == 0) cout << "SEGMENT\n"; 
    else cout << "IMPOSSIBLE\n";
    
	return 0;
}
