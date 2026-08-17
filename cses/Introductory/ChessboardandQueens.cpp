/*
 *	NOME: Chessboard and Queens
 *	LINK: https://cses.fi/problemset/task/1624
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int put(vector<vector<int>> visited, int row) {
    if(row == 8) return 1;

    int ways = 0;
    for(int col = 0; col < 8; col++){
        if(!visited[row][col]){
            vector<vector<int>> nextvisited = visited;
            for(int k = 0; k < 8; k++){
                nextvisited[row][k] = 1;
                nextvisited[k][col] = 1;
            }

            for(int k = 0; k < 8; k++){
                if(row + k < 8 && col + k < 8) nextvisited[row+k][col+k] = 1;
                if(row + k < 8 && col - k >= 0) nextvisited[row+k][col-k] = 1;
                if(row - k >= 0 && col + k < 8) nextvisited[row-k][col+k] = 1;
                if(row - k >= 0 && col - k >= 0) nextvisited[row-k][col-k] = 1;
            }

            ways+=put(nextvisited, row+1);
        }
    }
    return ways;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector <vector<char>> board(8, vector<char>(8));
    vector <vector<int>> visited(8, vector<int>(8, 0));
    for(int i=0; i < 8; i++){
    	for(int j=0; j < 8; j++){
    		char c; cin >> c;
    		if(c == '*') visited[i][j] = 1;
    	}
    }
    
    cout << put(visited, 0) << '\n';
	return 0;
}
