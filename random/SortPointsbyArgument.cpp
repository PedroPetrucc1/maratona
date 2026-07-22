#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    if (!(cin >> n)) return 0;
    
    vector<pair<long double, pair<long double, long double>>> num(n);
    long double x, y;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        
        long double angulo = atan2(y, x);
        
        angulo -= acos((long double)-1.0); //valor de pi 
        
        num[i].first = angulo;
        num[i].second = make_pair(x, y);
    }
    
    stable_sort(num.begin(), num.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });
    
    cout << fixed << setprecision(0);
    for(int i = 0; i < n; i++){
        cout << num[i].second.first << " " << num[i].second.second << '\n';
    }
    
    return 0;
}
