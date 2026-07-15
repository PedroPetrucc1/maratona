/*
 *	NOME: Counting Coprime Pairs
 *	LINK: https://cses.fi/problemset/task/2417
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MAX = 1e6;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector <ll> num(n);
	for(auto& v : num) cin >> v;
	
	vector<ll> mu(MAX+1, 1);
	vector<bool> prime(MAX+1, true);
	
	prime[0] = false;
	prime[1] = false;
	for(int i=2; (ll) i*i <= MAX; i++){ //implementacao do crivo de eratostenes
		if(prime[i]){
			for(ll j = i*i; j <= MAX; j+=i) prime[j] = false;
		}
	}
	
	for(int i=2; i <= MAX; i++){ //implementacao da funcao Mobius
		if(prime[i]){
			for(int j= i; j <= MAX; j += i){
				mu[j] *= -1;
			}
			
			for(ll j = (ll) i*i; j <= MAX; j += (i*i)){
				mu[j] *= 0;
			}
		}
	}

	vector<ll> freq(MAX+1, 0);
	for(ll k: num) freq[k]++;
	
	vector<ll> cnt(MAX+1, 0); //armazena a quantidade de multiplos que um numero tem no array de entrada
	for(int i=1; i <= MAX; i++){
		for(int j=i; j <=MAX; j+= i){
			cnt[i] += freq[j];
		}
	}

	ll ans = 0;
	for(int i=1; i <= MAX; i++){
		ans += (mu[i] * cnt[i] * (cnt[i]-1) / 2);
	}
	
	cout << ans << '\n';
	return 0;
}
