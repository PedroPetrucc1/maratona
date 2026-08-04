/*
 *	NOME: Integer Points
 *	LINK: https://codeforces.com/problemset/problem/1248/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
    	int n, m; cin >> n;
    	pair <ll, ll> p = make_pair(0,0), q = make_pair(0,0); //.first = par e .second = impar
    	while(n--){	
    		int a; cin >> a;
    		if(a%2 == 0)p.first++;
    		else p.second++;
    	}
    	cin >> m;
    	while(m--){
    		int b; cin >> b;
    		if(b%2 == 0) q.first++;
    		else q.second++;
    	}
    	
    	cout << p.first*q.first + p.second*q.second << '\n';
    }
	return 0;
}
