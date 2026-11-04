#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int OFF = 1000001;  // y = -1e6 vira indice 1
	const int SZ = 2000003;
	vector<int> bit(SZ + 1, 0);
	//estrutura de dados chamada Fenwick Tree ou então BIT (Binary Indexed Tree)

	int n; cin >> n;

	// evento: (x, tipo, a, b)
	// tipo 0: insercao horizontal (a = y)
	// tipo 1: consulta vertical   (a = y1, b = y2)
	// tipo 2: remocao horizontal  (a = y)

	vector<array<int,4>> ev;
	ev.reserve(2 * n);

	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);

		if(y1 == y2 && x1 != x2){
			ev.push_back({x1, 0, y1, 0});
			ev.push_back({x2, 2, y1, 0});
		} else {
			ev.push_back({x1, 1, y1, y2});
		}
	}

	sort(ev.begin(), ev.end());

	ll count = 0;
	for(auto &e : ev){
		int tipo = e[1];
		if(tipo == 0 || tipo == 2){
			int delta = (tipo == 0) ? 1 : -1;
			for(int p = e[2] + OFF; p <= SZ; p += p & -p) bit[p] += delta;
		} else {
			ll soma = 0;
			for(int p = e[3] + OFF; p > 0; p -= p & -p) soma += bit[p];
			for(int p = e[2] + OFF - 1; p > 0; p -= p & -p) soma -= bit[p];
			count += soma;
		}
	}

	cout << count << endl;
	return 0;
}
