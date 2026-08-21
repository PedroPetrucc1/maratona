#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    ll a, b, n; cin >> a >> b >> n;
    cout << ((b*n <= a || b >= a) ? 1 : 2) << '\n';
  }
}
