#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		ll high = 2e9, low = 1;
		ll ans = high;
		
		while(high >= low){
			ll mid = (low + high)/2;
			
			ll divi = mid - (mid/n);
			
			if(divi >= k){
				ans = mid;
				high = mid-1;
			}else low = mid+1;
		}
		
		cout << ans << endl;
	}
}
