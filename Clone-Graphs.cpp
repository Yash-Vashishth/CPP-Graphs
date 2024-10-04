/*
You are given a reference/address of a node in a connected undirected graph containing 
N nodes and M edges. You are supposed to return a clone of the given graph which is nothing 
but a deep copy. Each node in the graph contains an integer “data” and an array/list of its 
neighbours.
The structure of the graphNode class is as follows:
class graphNode 
{  
    public:
        int data;
        vector<graphNode*> neighbours;
}
Note :
1. Nodes are numbered from 1 to N.

2. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
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
