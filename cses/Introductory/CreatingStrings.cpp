/*
 *	NOME: Creating Strings
 *	LINK: https://cses.fi/problemset/task/1622
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set <string> resultado;

void permutar(string s, int inicio, int fim){
	if(inicio == fim){
		resultado.insert(s);
		return;
	}
	
	for(int i=inicio; i <= fim; i++){
		char temp = s[inicio];
		s[inicio] = s[i];
		s[i] = temp;
		
		permutar(s, inicio+1, fim);
		
		temp = s[inicio];
		s[inicio] = s[i];
		s[i] = temp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	permutar(s, 0, s.size()-1);
	
	cout << resultado.size() << '\n';
	for(string k : resultado) cout << k << '\n';
	return 0;
}
