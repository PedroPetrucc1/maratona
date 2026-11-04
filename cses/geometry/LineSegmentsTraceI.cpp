#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll n, m; cin >> n >> m;
	map <ll, ll> best;
 
	for(int i=0; i < n; i++){
		ll a, b; cin >> a >> b;
		ll cof = (b-a)/m;
		if(!best.count(cof) || a >  best[cof]) best[cof] = a;
	}
 
	vector <pair<ll, ll>> st;
	for(auto &p : best){
		ll c3 = p.first, a3 = p.second;
		while(st.size() >= 2){
			ll a1 = st[st.size()-2].first, c1 = st[st.size()-2].second;
			ll a2 = st[st.size()-1].first, c2 = st[st.size()-1].second;
			if((a2-a3)*(c2-c1) <= (a1-a2)*(c3-c2)) st.pop_back();
			else break;
		}
		st.push_back({a3, c3});
	}
 
	int ptr = 0;
	for(int i=0; i <= m ;i++){
		while(ptr+1 < (int)st.size() && 
		st[ptr+1].first + st[ptr+1].second*i >= st[ptr].first + st[ptr].second*i) ptr++;
		cout << st[ptr].first + st[ptr].second*i << " ";
	}
 
	cout << endl;
	return 0;
}
