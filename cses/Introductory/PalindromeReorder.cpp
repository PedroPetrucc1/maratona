#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    
    vector<int> qtd(26, 0);
    for(char c : s) qtd[c - 'A']++;
    
    int impar = 0;
    int indximpar = -1;
    
    for(int i = 0; i < 26; i++){
        if(qtd[i] % 2 == 1){
            impar++;
            indximpar = i;
        }
    }
    
    if(impar > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    string metade_esquerda = "";
    string meio = "";
    
    for(int i = 0; i < 26; i++){
        if(i == indximpar){
            meio = string(qtd[i], 'A' + i);
        } else {
            metade_esquerda += string(qtd[i] / 2, 'A' + i);
        }
    }
    

    string metade_direita = metade_esquerda;
    reverse(metade_direita.begin(), metade_direita.end());
    

    cout << metade_esquerda << meio << metade_direita << '\n';
    
    return 0;
}
