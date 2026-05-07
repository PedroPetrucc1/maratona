/*
 * LINK: https://cses.fi/problemset/task/1070
 * NOME: Permutations
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;cin>>n;
	if(n%2 == 0){
		if(n == 2){cout << "NO SOLUTION";return 0;}
		if(n==4){cout << 2 << " " << 4  << " " << 1  << " " << 3; return 0;}
		int temp = n;
		for(int i=0; i < (n/2)-1; i++){
			cout << temp << " ";
			temp -= 2;
		}
		temp = 1;
		for(int i=0; i < (n/2); i++){
			cout << temp << " ";
			temp += 2;
		}
		cout << 2;
		
	}else{
		if(n == 3){cout << "NO SOLUTION";return 0;}
		int temp = n-1;
		for(int i=0; i < (n-1)/2; i++){
			cout << temp << " ";
			temp -= 2;
		}
		temp = n;
		for(int i=0;i<(n+1)/2; i++){
			cout << temp << " ";
			temp -= 2;
		}
	}
	return 0;
}
