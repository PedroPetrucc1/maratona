/*
 *	NOME: Queue Mischief
 *	LINK: https://codeforces.com/gym/106667/problem/G
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  int n; cin >> n;
  deque<char> lst;
  
  ll sum = 0, ac = 0, bc = 0;
  while (n--) {
    int t; cin >> t;
    if (t == 1) {
      char l; cin >> l;
      lst.push_back(l);
      if (l == 'A') ac++;
      else          sum += ac, bc++;
      
    } else if (t == 2) {
      char l; cin >> l;
      lst.push_front(l);
      if (l == 'A') sum += bc, ac++;
      else          bc++;
      
    } else if (t == 3) {
      char l = lst.back();
      lst.pop_back();
      if (l == 'A') ac--;
      else          sum -= ac, bc--;
    } else {
      char l = lst.front();
      lst.pop_front();
      if (l == 'A') sum -= bc, ac--;
      else          bc--;
    }
    cout << sum << endl;
  }
}
