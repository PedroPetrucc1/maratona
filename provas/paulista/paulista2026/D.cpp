/*
 *	NOME: Drawing SP
 *	LINK: https://codeforces.com/gym/106598/problem/D
*/

#include <bits/stdc++.h>

using namespace std;

int main(){	
	int n; cin >> n;
	
	for(int i=0; i < n; i++) cout << " ";
	for(int i=0; i < n+1; i++) cout << "_";
	cout << "\n";
	
	int spaces = n+1;
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++) cout << " ";
		cout << "/";
		for(int j=0; j < spaces; j++) cout << " ";
		spaces += 2;
		cout << "\\" << endl;
	}
	
	cout << "/";
	for(int i=0; i < n; i++) cout << "_";
	for(int i=0; i < n*2-1; i++) cout << " ";
	cout << "\\";
	for(int i=0; i < n+1; i++) cout << "_";
	cout << "\n";
	
	for(int i=0; i < n-1; i++){
		for(int j=0; j < n+1+i; j++) cout << " ";
		cout << "\\";
		for(int j=0; j < spaces; j++) cout << " ";
		spaces -= 2;
		cout << "/" << endl;
	}
	
	for(int i=0; i < n*2; i++) cout << " ";
	cout << "\\";
	for(int i=0; i < n+1; i++) cout << "_";
	cout << "/";
		
	return 0;
}
