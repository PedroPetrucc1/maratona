/*
 *	NOME: Youth Divisions
 *	LINK: https://codeforces.com/gym/106667/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 998244353;
vector <ll> fat(1e5+1), invfat(1e5+1);
  
ll binpow(ll base, ll exp){
  if(exp == 0) return 1;
  ll ans = binpow(base, exp/2);
  if(exp%2 == 1){
    return (((ans*ans)%MOD)*base)%MOD;
  }else{
    return (ans*ans)%MOD;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, k; cin >> n >> k;
  unordered_map <ll, ll> mp;
  mp.reserve(1e5+1);
  vector <ll> profession;
    
  ll maxgroup = -1;
  for(int i=0; i < n; i++){
    ll a; cin >> a;
    mp[a]++;
    maxgroup = max(maxgroup, mp[a]);
  }
  
    unordered_map<ll, ll> size_counts;
    size_counts.reserve(1e5+1);
    for (auto [role, count] : mp) {
        size_counts[count]++;
  }
  
  if(maxgroup > k){
    cout << 0 << '\n';
    return 0;
  }
  
  int cont = 1;
  fat[0] = 1;
  invfat[0] = 1;
  while(cont <= 1e5){
    fat[cont] = (fat[cont-1]*cont)%MOD;
    invfat[cont] = binpow(fat[cont], MOD-2);
    cont++;
  }

  ll ans = 0;
  
  for(int i=1; i <= k; i++){
    if(maxgroup > i) continue;
    
    ll L_j = 1;
    for (auto [c_j, num_professions] : size_counts) {
            ll perm = (fat[i] * invfat[i - c_j]) % MOD;
            L_j = (L_j * binpow(perm, num_professions)) % MOD;
        }
    
    L_j = ((invfat[i]*invfat[k-i])%MOD * L_j)%MOD;
    if((k-i)%2 == 0){
      ans = (ans + L_j)%MOD;
    }else{
      ans = (ans - L_j + 2*MOD)%MOD;
    }
  }
  
  cout << ans << '\n';
  return 0;
}
 
