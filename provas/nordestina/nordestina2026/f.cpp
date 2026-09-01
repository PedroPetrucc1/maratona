/*
 *	NOME: Escaping the Sun
 *	LINK: https://codeforces.com/gym/106667/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, h; cin >> n >> h;
  
  vector<pair<array<ll, 2>, double>> ver(n);
  vector<vector<pair<int, double>>> adj(n+1);
  
  for (auto &[v, r]: ver) cin >> v[0] >> v[1] >> r;
  
  priority_queue<pair<double, int>> pq;
  
  for (int i = 1; i <= n; i++) {
    auto &[v, r] = ver[i-1];
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      auto &[v2, r2] = ver[j-1];
      auto w = max((double)0, (double)(sqrt(pow((v[0] - v2[0]), 2) + pow((v[1] - v2[1]), 2)) - r - r2)); 
      adj[i].emplace_back(j, w);
    }
    
    adj[i].push_back({n+1, max((double)0, (double)(h - v[1] - r))});
    pq.push({-max((double)0, (double)(v[1] - r)), i});
  }
  
  vector<double> dist(n+2, h);
  while (!pq.empty()) {
    auto [w, v] = pq.top();
    w = -w;
    pq.pop();
    if (v == n+1) break;
    if (dist[v] < w) continue;
    
    for (auto [u, w2]: adj[v]) {
      if (dist[u] > w2+w) {
        dist[u] = w2+w;
        pq.push({-(w+w2), u});
      }
    }
  }
  printf("%.10lf\n", dist[n+1]);
  return 0;
}
