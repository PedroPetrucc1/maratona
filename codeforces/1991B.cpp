#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector <int> b(n-1), a(n);
		for(auto &v : b) cin >> v;
		a[0] = b[0];
		a[n-1] = b[n-2];
		
		for(int i=1; i < n-1; i++) a[i] = (b[i-1] | b[i]);

		bool ok = true;
		for(int i=0; i < n-1 && ok; i++)
			if((a[i] & a[i+1]) != b[i]) ok = false;
		
		if(!ok) cout << -1 << endl;
		else{
			for(auto k : a) cout << k << " "; cout << endl;
		}
	}
	return 0;
}