/*
 *	NOME: Prime Multiples
 *	LINK: https://cses.fi/problemset/task/2185
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(auto& l : primes) cin >> l;
    
    vector <ll> numberDivisors(k+1);
    for(int mask = 1; mask < (1 << k); mask++){
    	int number = 0;
    	ll temp = n;
    	for(int i=0; i < k; i++){
    		if((1<<i)&mask){
    			number++;
    			temp /= primes[i];
    		}
    	}
    	
    	numberDivisors[number] += temp;
    }
    
    ll ans = 0;
    for(int i =1; i <= k; i++){
    	if(i%2 == 0) ans -= numberDivisors[i];
    	else ans += numberDivisors[i];
    }
    
    cout << ans << '\n'; 
	return 0;
}
