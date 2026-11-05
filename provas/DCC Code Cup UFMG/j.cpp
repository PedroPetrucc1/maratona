//Link: https://codeforces.com/gym/106800/problem/J

#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  
  vector<pair<int, int>> lw(n), up(n);
  vector<int> day(n, 1e7);
  for (int i = 0; i < n; i++) {
    cin >> lw[i].first >> up[i].first;
    lw[i].second = up[i].second = i;
  }
  sort(lw.begin(), lw.end());
  sort(up.begin(), up.end());
  
  int lwl = 0, lwr = n-1, upl = 0, upr = n-1;
  for (int i = 1; i <= m; i++) {  
    int l, r; cin >> l >> r;
    {
      auto lit = upper_bound(lw.begin(), lw.end(), pair<int, int>({l, 1e7}));
      auto uit = lower_bound(up.begin(), up.end(), pair<int, int>({l, -1}));
      //cout << (*lit).first << endl;
      for (int j = lwr; j >= lit - lw.begin(); j--) day[lw[j].second] = min(i, day[lw[j].second]);
      //cout << "1: " <<day[1] << endl;
      lwr = min((int)(lit-lw.begin()-1), lwr);
      for (int j = lwl; j < uit - up.begin(); j++) day[up[j].second] = min(i, day[up[j].second]);
      //cout << "2: " << day[1] << endl;
      lwl = max((int)(uit-up.begin()), lwl);
    }
    
    {
      auto lit = upper_bound(lw.begin(), lw.end(), pair<int, int>({r, 1e7}));
      auto uit = lower_bound(up.begin(), up.end(), pair<int, int>({r, -1}));
    
      for (int j = upr; j >= lit - lw.begin(); j--) day[lw[j].second] = min(i, day[lw[j].second]);
      upr = min((int)(lit-lw.begin()-1), upr);
      //cout << "3: " << day[1] << endl;

      for (int j = upl; j < uit - up.begin(); j++) day[up[j].second] = min(i, day[up[j].second]);
      upl = max(upl, (int)(uit-up.begin()));
      //cout << "4: " << day[1] << endl;
    }
    
  }
  for (int i = 0; i < n; i++) 
    if (day[i] != 1e7) cout << day[i] << endl;
    else               cout << -1 << endl;
  return 0;
}


// 11 20

// 7 20
