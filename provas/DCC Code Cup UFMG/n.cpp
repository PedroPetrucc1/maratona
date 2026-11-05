//Link: https://codeforces.com/gym/106800/problem/N

#include <bits/stdc++.h>

using namespace std;

int main(){
  int a1, l1, a2, l2, a3, l3, a4, l4, ap, lp;
  cin >> a1 >> l1 >> a2 >> l2 >> a3 >> l3 >> a4 >> l4 >> ap >> lp;
  if(a2 > a1 || a3 > a1 || l2 > l1 || l3 > l1 || a1 > ap || a4 > ap || l1 > lp || l4 > lp) cout << "NAO" << endl;
  else if((a2+a3) > a1 && (l2+l3) > l1) cout << "NAO\n";
  else if((a1+a4) > ap && (l1+l4) > lp) cout << "NAO\n";
  else cout << "SIM\n";
  return 0;
}
