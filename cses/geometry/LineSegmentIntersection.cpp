/*
 *	NOME: Line Segment Intersection
 *	LINK: https://cses.fi/problemset/task/2190
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sing(ll num){ //pega apenas o sinal da reta, ou seja, o sentido
	if(num < 0) return -1;
	else if(num == 0) return 0;
	else return 1;
}

ll collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	return sing((y1-y2)*(x3-x1) - (x1-x2)*(y3-y1));
}

bool quick_check(ll px1, ll py1, ll px2, ll py2, ll px3, ll py3, ll px4, ll py4){ //verifica se podem se tocar atraves dos retangulos
	ll x1 = min(px1, px2), x2 = max(px1, px2);
	ll y1 = min(py1, py2), y2 = max(py1, py2);
	ll x3 = min(px3, px4), x4 = max(px3, px4);
	ll y3 = min(py3, py4), y4 = max(py3, py4);
	return x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1;
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){ //verifica se estao em sentidos opostos
	if(collinear(x1, y1, x2, y2, x3, y3) * collinear(x1, y1, x2, y2, x4, y4) > 0) return false;
	if(collinear(x3, y3, x4, y4, x1, y1) * collinear(x3, y3, x4, y4, x2, y2) > 0) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	ll x1, x2, x3, x4, y1, y2, y3, y4;
    	cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3 >> x4 >> y4;
    	
    	if(quick_check(x1, y1, x2, y2, x3, y3, x4, y4)) cout << "NO\n";
    	else if(check(x1, y1, x2, y2, x3, y3, x4, y4)) cout << "YES\n";
    	else cout << "NO\n";
    }
    
	return 0;
}
