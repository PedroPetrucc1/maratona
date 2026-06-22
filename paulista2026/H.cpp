/*
 *	NOME: Driving restriction schedule
 *	LINK: https://codeforces.com/gym/106598/problem/H
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, time = 300; cin >> n;
	
	while(n--){
		int a; cin >> a;
		time += a;
		if((time > 420 && time < 600) || (time > 1020 && time < 1200)) time += 180;
	}
	
	cout << time - 300 << "\n";
	return 0;
}
