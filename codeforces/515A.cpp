#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, s; cin >> a >> b >> s;
  cout << (((s >= abs(a)+abs(b)) && (s-(abs(a)+abs(b)))%2 == 0) ? "Yes" : "No") << '\n';
}
