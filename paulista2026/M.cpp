/*
 *	NOME: Multi-word
 *	LINK: https://codeforces.com/gym/106598/problem/M
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s, t, st, ts; 
	long p, q;
	cin >> s >> t >> p >> q;
	st = s+t;
	ts = t+s;
	
	if(!p || !q){cout << "=\n"; return 0;}
	
	for(int i=0; i < st.size(); i++){
		if(st[i] > ts[i]) {cout << ">\n"; return 0;}
		else if(st[i] < ts[i]) {cout << "<\n"; return 0;}
	}
	
	cout << "=\n";
	
}
