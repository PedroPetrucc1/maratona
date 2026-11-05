//Link: https://codeforces.com/gym/106800/problem/B

#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b; cin >> a >> b;
  if(a > b) swap(a, b);
  cout << a + (b-a)/5 << endl;
  return 0;
}
