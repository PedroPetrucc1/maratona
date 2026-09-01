/*
 *	NOME: The Brega Game
 *	LINK: https://codeforces.com/gym/106667/problem/J
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace seg {
  vector<ll> t(4e5+2);
  int n;
  void build(int sz) {
    n = sz;
    for (int i = n-1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
  }
  
  ll query(int l, int r) {
    ll res = 0;
    for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
      if (l&1) res = max(res, t[l++]);
      if (r&1) res = max(res, t[--r]);
    }
    return res;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, q; cin >> n >> q;
  vector <ll> num(n+2);

  for(int i=1; i <= n;i++){
    cin >> seg::t[i+n+1];
    num[i] = seg::t[i+n+1];
  }
  
  seg::build(n+1);
  
  while(q--){
    int l, r; cin >> l >> r;
    if((r-l+1)%2 == 0 || l == r){
      cout << "Adilson\n";
      continue;
    }
    
    auto mx = seg::query(l, r+1);
    //cout << mx << ": ";
    if (mx == num[l] || mx == num[r]) 
      cout << "Adilson\n";
    else
      cout << "Reginaldo\n";
  }
  
  return 0;
}
