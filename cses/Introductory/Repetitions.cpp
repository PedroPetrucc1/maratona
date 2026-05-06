/*
 * LINK: https://cses.fi/problemset/task/1069
 * NOME: Repetitions
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	int n = s.size()-1, maior =1, atual = 1;
	for(int i=0; i < n; i++){
		if(s[i] == s[i+1]){
			atual++;
			maior = max(maior, atual);
		}else{
			atual = 1;
		}
	}
	cout << maior;
}
