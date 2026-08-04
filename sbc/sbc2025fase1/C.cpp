/*
 *	NOME: Collatz polynomial
 *	LINK: https://codeforces.com/gym/106073/problem/C
*/
 
#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector <int> p(n+1);
    for(int i=0; i <= n; i++)cin >> p[i];
    reverse(p.begin(), p.end());
    
    int count = 0, sum;
    if(n == 0){
    	if(p[0]){
    		cout << 0 << '\n';
    		return 0;
    	}else{
    		cout << 1 << '\n';
    		return 0;
    	}
    }
    while(true){
    	if(p[0]){
    		p.push_back(0);
    		vector <int> p2(p.size());
    		p2 = p;
    		for(int i=0; i < p.size()-1; i++) p2[i+1] = (p[i]+p[i+1])%2;
    		p = p2;
    		p[0] = 0;
    	}else{
    		for(int i=1; i <= p.size(); i++) p[i-1] = p[i];
    		p.pop_back(); 
    	}
    	
    	count++;
    	sum = 0;
    	for(int k : p) sum += k;
    	if(sum == 1 && p[0] == 1) break;
    }
    cout << count << "\n";
	return 0;
}
