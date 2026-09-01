/*
 *	NOME: The Scale Riddle
 *	LINK: https://codeforces.com/gym/106667/problem/E
*/

#include <bits/stdc++.h>

using namespace std;

int solve (int l, int r) {
  if (l == r) return l;
  if (l == r-1) {
    cout << "? " << 1 << ' ' << l << ' ' << r << endl;
    char op; cin >> op;
    if (op == 'D') return r;
    else return l;
  }
  
  int off = (r-l+1)/3; // 4-1+1/3 = 1
  if (((r-l+1) % 3) == 1) off++;
  int t = (r-off-l+1)/2; // 4 - 1 - 1 + 1 / 2
  cout << "? " << t << ' ';
  for (int i = l; i <= r-off; i++) cout << i << ' ';
  cout << endl;
  
  char op; cin >> op;
  
  if (op == 'I') return solve(r-off+1, r);  // 8 t = 3, l = 1, r = 8, off = 2, 
  if (op == 'D') return solve(l+t, r-off);
  if (op == 'E') return solve(l, r-off-t);
  cout << "ERRROOOOO" << endl;
  return l;
}

int main(void) {
  int n; cin >> n;
  int v = solve(1, n);
  cout << "! " << v << endl;
  return 0;
}
