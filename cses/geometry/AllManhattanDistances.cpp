/*
 *	NOME: All Manhattan Distances
 *	LINK: https://cses.fi/problemset/task/3411
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

__int128 ManhattanDistance(vector <ll>& coord){
	__int128 sum = 0, ans = 0;
	for(int i=0; i < n; i++){
		ans += coord[i] * i - sum;
		sum += coord[i];
	}
	return ans;
}

void print128(__int128 x){
	if(x == 0){
		cout << 0 <<'\n';
		return;
	}
	
	if(x < 0){
		cout << '-';
		x = -x;
	}
	
	string res;
	while(x > 0){
		res += (x%10) + '0';
		x /= 10;
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector <ll> x(n), y(n);
    for(int i=0; i < n; i++) cin >> x[i] >> y[i];
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    print128(ManhattanDistance(x) + ManhattanDistance(y));
	return 0;
}
