/*
 *	NOME: Lexicographical Challenge
 *	LINK: codeforces.com/gym/104555/problem/L
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector <bool> visited(n, 0);
    for(int i=0; i < n; i++){
    	if(visited[i]) continue;
    	vector <int> atual;
    	for(int j=i; j < n; j += k){
    		visited[j] = 1;
    		atual.push_back(s[j]);
    	}
    	sort(atual.begin(), atual.end());
    	int count = 0;
    	for(int j=i; j < n; j += k){
    		s[j] = atual[count];
    		count++;
    	}
    }
    
    cout << s << '\n';
	return 0;
}
