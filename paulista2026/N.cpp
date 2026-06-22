/*
 *	NOME: Reactivity levels
 *	LINK: https://codeforces.com/gym/106598/problem/N
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n; cin >> n;
	long long s, m;
	vector <long long> vb(n+2);
	
	for(auto &v : vb) cin >> v;
	sort(vb.begin(), vb.end());
	
	s = vb[n+1];
	vector <long long> va;
	
	long long sum = 0;
	for(int i=2; i < n+1;i++){
		va.push_back(s - vb[i]);
		sum += (s-vb[i]);
	}
	
	m = s - sum;
	va.push_back(m);
	sort(va.begin(), va.end());
	
	cout << s << " " << m << "\n"; 
	for(auto k : va) cout << k << " ";
	cout << "\n";
	
	return 0;
}
