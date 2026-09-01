/*
 *	NOME: Good Spotlights
 *	LINK: https://codeforces.com/gym/106667/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string line; cin >> line;

  vector<string> table = {"010", "110", "111", "101", "100", "000", "001", "011"};
  int ind;
  for (int i = 0; i < table.size(); i++) if (table[i] == line) ind = i;
  for (int i = ind; i <= ind+8; i++) cout << table[i%8] << endl;
  
  return 0;
}
