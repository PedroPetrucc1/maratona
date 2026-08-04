/*
 *	NOME: Lecographically Maximum
 *	LINK: https://codeforces.com/gym/105327/problem/L
*/
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector <int> bits(32, 0);
    int n; cin >> n;
    for(int i=0; i < n; i++){
    	int a; cin >> a;
    	for(int j=0; j < 32; j++){
    		int bit = (a >> j) & 1;
    		bits[j] += bit;
    	}
    }
    
    for(int i=0; i < n; i++){
    	int num = 0;
    	for(int j=0; j < 32; j++){
    		if(bits[j] > 0){
    			num |= (1 << j);
    			bits[j]--;
    		}
    	}
    	cout << num << " ";
    }
    cout << '\n';
	return 0;
}
