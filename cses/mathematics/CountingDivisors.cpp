/*
 *	NOME: Counting Divisors
 *	LINK: https://cses.fi/problemset/task/1713
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int queries; cin >> queries;
	while(queries--){
	
	    ios_base::sync_with_stdio(false);
    	cin.tie(NULL); //otimizacao da entrada
    	
		int num; cin >> num;
		vector <int> PowerPrimeFactors;
		for(int i=2; i*i <= num; i++){ //implementacao do algoritmo
		
			if(num%i == 0){
			
				int power = 0;
				
				while(num % i == 0){
					power++;
					num /= i;
				}
				PowerPrimeFactors.push_back(power);
			}
		}
		
		if(num != 1) PowerPrimeFactors.push_back(1);
		
		int NumberDivisors = 1;
		for(int k : PowerPrimeFactors){
			NumberDivisors *= (k+1);
		}
		
		cout << NumberDivisors << "\n";
	}
	return 0;
}
