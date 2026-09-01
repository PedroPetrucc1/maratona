/*
 *	NOME: Karamelos at São João
 *	LINK: https://codeforces.com/gym/106667/problem/K
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int a, x; cin >> a >> x;
  for (int i = 1; i <= 1e8; i++) {
    if (x*i > a && x*i % a == 1) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
 
