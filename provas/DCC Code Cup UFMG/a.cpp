//Link: https://codeforces.com/gym/106800/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int d = 0, c = 0;
    for(auto C : s) if(C == 'D') d++; else c++;
    if(c > (d+1)*4 || c < (d-1)*4 || c <= 0 || d <= 0) cout << -1;
    else{
      int resto = (c == d*4+4 ? 4 : c%4);
      c -= (resto);
      while(resto--) cout << 'C';
      for(int i=0; c > 0 || d > 0; i++){
        if(i%5 == 0) cout << 'D', d--;
        else cout << 'C', c--;
      }
    }
    cout << endl;
  }
  return 0;
}
