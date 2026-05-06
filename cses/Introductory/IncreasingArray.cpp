/*
 * LINK: https://cses.fi/problemset/task/1094
 * NOME: Increasing Array
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, min_dif = 0; cin >> n;
	long v[n];
	for(int i=0; i < n; i++){cin >> v[i];}
	for(int i=1; i < n; i++){
		if(v[i] < v[i-1]){
			min_dif += v[i-1]-v[i];
			v[i] = v[i-1];
		}
	}
	cout << min_dif;
	return 0;
}
