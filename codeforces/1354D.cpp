#include <bits/stdc++.h>

using namespace std;

int MAX = 1000005;
int BIT[1000005];
int n, q;

void update(int k, int v){
	while(k < MAX){
		BIT[k] += v;
		k += (k & -k);
	}
}


int query(int k){
	int s = 0;
	while(k > 0){
		s += BIT[k];
		k -= (k & -k);
	}	
	return s;
}

int kth(int k){
	int l = 1, r = n;
	while(l < r){
		int mid = (l+r)/2;
		if(query(mid) >= k) r = mid;
		else l = mid+1;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	int total = n;
	for(int i =0; i < n; i++){
		int a; cin >> a;
		update(a, 1);
	}

	while(q--){
		int k; cin >> k;
		if(k > 0){
			update(k, 1);
			total++;
		}else{
			int v = kth(-k);
			update(v, -1);
			total--;	
		}
	}

	if(total == 0) cout << 0 << endl;
	else cout << kth(1) << endl;
	return 0;
}