/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours 
denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play 
a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call 
a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the 
board.
*/ 
#include <iostream>
#include <vector>
using namespace std;
bool isValid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool hasCycle(vector<vector<char>> &board, int n, int m, int i , int j, int parentX, int parentY, vector<vector<bool>> &visited){
    visited[i][j] = true;

    int neighbourX[4] = {-1, 1, 0 , 0};  //TOP
    int neighboutY[4] = { 0, 0, -1, 1};

    for(int k = 0; k < 4; k++){
        int newX = i + neighbourX[k];
        int newY = j + neighboutY[k];
        
        if(newX == parentX && newY == parentY) continue;

        if( isValid(newX, newY, n, m) && board[newX][newY] == board[i][j] /*&& !(newX == parentX && newY == parentY) */ ){

            if(visited[newX][newY] && (newX != parentX && newY != parentX)) return true;    // this is correct line to check 2nd condtn as per code logic

            else if(hasCycle(board, n, m, newX, newY, i, j, visited)){
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                if(hasCycle(board, n, m, i , j, -1, -1, visited)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasCycle(board, n, m) ? "true" : "false");
}