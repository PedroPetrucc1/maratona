#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int n; cin >> n;
	string s; cin >> s;
	int best = 0;
	for(int i=1; i*2 <= n; i++){
		bool ok = true;
		for(int j=0; j < i && ok; j++)
			if(s[j] != s[i+j]) ok = false;
		if(ok) best = i;
	}
	
	if(best == 0) cout << n << endl;
	else cout << n-best+1 << endl;
	return 0;
}