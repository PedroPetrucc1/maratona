#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x, y; cin >> x >> y;
    if(x > 0 && y > 0) cout << 0 << " " << x+y << " " << x+y << " " << 0 << endl;
    else if(x > 0 && y < 0)  cout << 0 << " " << -(x+abs(y)) << " " << x+abs(y) << " " << 0 << endl;
    else if(x < 0 && y < 0) cout << -(abs(x) + abs(y)) << " " << 0 << " " << 0 << " " << -(abs(x) + abs(y)) << endl;
    else cout << -(abs(x) + y) << " " << 0 << " " << 0 << " " << abs(x)+y << endl;

    return 0;
}