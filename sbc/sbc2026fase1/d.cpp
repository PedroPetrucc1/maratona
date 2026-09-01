/*
 * NOME: Dragons in Harmony
 * LINK: https://codeforces.com/gym/106679/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;

bool igual(vector<vector<char>> v, vector<vector<char>> p){
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			if(v[i][j] != p[i][j]) return false;
		}
	}
	return true;
}

vector<vector<char>> noventa(vector<vector<char>> v){
	vector <vector<char>> k(n+2, vector<char>(m+2));
	
	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			k[i][j] = v[n-j-1][i];
		}
	}
	
	return k;
}

vector<vector<char>> espelha(vector<vector<char>> v){
	vector <vector<char>> k(n+2, vector<char>(m+2));
	
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			k[i][j] = v[i][m-j-1];	
		}
	}
	
	return k;
}

vector<vector<char>> centoeoitenta(vector<vector<char>> v){
	vector <vector<char>> k(n+2, vector<char>(m+2));
	
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			k[i][j] = v[n-i-1][m-j-1];	
		}
	}
	
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	vector<vector<char>> p(n+2, vector<char>(m+2)), v1(n+2, vector<char>(m+2));
	
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			cin >> p[i][j];
			v1[i][j] = p[i][j];
		}
	}
	
	int total = 0;
	if(m ==  n){
		for(int i=0; i < 4; i++){
			v1 = noventa(v1);
			if(igual(v1, p)) total++;
		}
		v1 = espelha(v1);
		for(int i=0; i < 4; i++){
			v1 = noventa(v1);
			if(igual(v1, p)) total++;
		}
	}else{
		if(igual(v1, p)) total++;
		if(igual(centoeoitenta(v1), p)) total++;
		v1 = espelha(v1);
		if(igual(v1, p)) total++;
		if(igual(centoeoitenta(v1), p)) total++;
	}
	
	cout << total << '\n';
	
	return 0;
}
