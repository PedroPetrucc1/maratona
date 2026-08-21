/*
 * NOME: Olesya and Rodion
 * LINK: https://codeforces.com/problemset/problem/584/A
*/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	string t;
	cin >> n >> t;
	string s = "";
	if(t == "10"){
		if(n == 1){
			s = "-1";
		}else{
			for(int i=0; i < n-1;i++) s += "1";
			s += "0";
		}
	}else{
		for(int i=0; i < n; i++) s += t;
	}
	
	cout << s << '\n';
	
	return 0;
}
