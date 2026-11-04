#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <int> num;
int n; 

ll sum(ll idx, ll sum1, ll sum2){
    if(idx == n) return(abs(sum1-sum2));
    
    ll group1 = sum(idx+1, sum1+num[idx], sum2);
    ll group2 = sum(idx+1, sum1, sum2+num[idx]);
    
    return min(group1, group2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    num.resize(n);
    for(auto &v : num) cin >> v;

    cout << sum(0, 0, 0) << '\n';

    return 0;
}
