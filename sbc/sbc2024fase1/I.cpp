/*
 *	NOME: Ingredients that may Harm You   
 *	LINK: https://codeforces.com/gym/105327/problem/I
*/
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;
ll MAXV = 1e6;
int invalidos;
vector <int> multiplos(MAXV+1, 0);

ll binpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll res = binpow(base, exp/2);
	if(exp%2 == 1) return (((res*res)%MOD)*base)%MOD;
	else return (res*res)%MOD;
}


void pie(int idx, ll produto, int usados, const vector<int>& primos) {
    if (produto > MAXV) return;

    if (idx == primos.size()) {
        if (usados == 0) return;
        
        if (usados % 2 == 1) {
            invalidos += multiplos[produto];
        } else {
            invalidos -= multiplos[produto];
        }
        return;
    }

    pie(idx+1, produto, usados, primos);

    pie(idx+1, produto*primos[idx], usados+1, primos);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    vector <int> freq(MAXV+1, 0);
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        freq[v]++;
    }
    
    for(int i = 1; i <= MAXV; i++) {
        for(int j = i; j <= MAXV; j += i) {
            multiplos[i] += freq[j];
        }
    }
    
    int q; cin >> q;
    while(q--){
    	ll a; cin >> a;
    	
    	vector <int> primos;
    	ll temp = a;
        for(ll j = 2; j * j <= temp; j++) {
            if(temp % j == 0) {
                primos.push_back(j);
                while(temp%j == 0) temp /= j;
            }
        }
        
        if(temp > 1) primos.push_back(temp);
        
        invalidos = 0;
        pie(0, 1, 0, primos);

        cout << binpow(2, n-invalidos) << '\n';        
    }
    
	return 0;
}
