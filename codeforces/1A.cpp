/*
 * NOME: Theatre Square
 * LINK: https://codeforces.com/problemset/problem/1/A
*/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a;
    cin >> n >> m >> a;
    ll lagesn = n/a, lagesm = m/a;
    if(n%a != 0)lagesn++;
    if(m%a != 0)lagesm++;
    ll total = (lagesn)*(lagesm);
    cout << total <<'\n';
}
