//Link: https://codeforces.com/gym/106800/problem/D

#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector <int> vs(1e5+1);
    for(int i=0; i < n; i++){
      int a; cin >> a;
      vs[a]++;
    }
    int teto = n;
    for(int i=1; i <= n; i++){
      if(vs[i] == 0) {cout << i-1 << endl; break;}
      teto = min(i+vs[i]-1, teto);
      if(i == teto) {cout << i << endl; break;}
    }
  }
  return 0;
}
