//Link: https://codeforces.com/gym/106800/problem/C

#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<string> s = {"Reformer", "Cadillac", "Chair", "Barrel"};
  int n; cin >> n;
  cout << s[--n%4] << endl;
  return 0;
}
