/*
 *	NOME: Lampions League
 *	LINK: https://codeforces.com/gym/106667/problem/L
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n; cin >> n;
  cout << (((n+1)/2)%2 == 0 ? "PAR\n" : "IMPAR\n");
  return 0;
}
