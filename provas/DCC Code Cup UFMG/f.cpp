//Link: https://codeforces.com/gym/106800/problem/F

#include <bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    int j = 0;
    for (auto c : a) if (b[j] == c) j++;
    if (j != b.size()) cout << "NAO" << endl;
    else               cout << "SIM" << endl;
  }
  return 0;
}
