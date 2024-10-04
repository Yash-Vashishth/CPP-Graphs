/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path 
in the given matrix which makes the sentence “CODINGNINJA” .There is a path from any cell to all its 
neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a 
corner with the cell.
*/ 
#include <iostream>
#include <vector>
using namespace std;

bool isValidPoint(int x, int y, int n, int m){           //updated
    return (x >= 0 && x < n && y >= 0 &&  y < m);
}

bool isValid(vector<vector<char>>& Graph, int n, int m, int i, int j, vector<vector<bool>>& visited, string& word, int index) {
    if (index == word.size()) {
        return true;
    }

    visited[i][j] = true;

    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, //top-left, top-mid, top-right
        {0, -1},{0, 1},                  //mid-left , mid-right           
        {1, -1}, {1, 0}, {1, 1}             //down-left, down-mid, down-right
    };

    for (int k = 0; k < 8; k++) {
        int newRow = i + directions[k][0];
        int newCol = j + directions[k][1];
        if( isValidPoint(newRow, newCol, n, m) && Graph[newRow][newCol] == word[index] && !visited[newRow][newCol]){
            if (isValid(Graph, n, m, newRow, newCol, visited, word, index + 1)) {     //if all condition satify, procees exploring next character 
                return true;
            }
        }  
    }

    visited[i][j] = false;
    return false;
}

bool hasPath(vector<vector<char>> &Graph, int n, int m) {
    string word = "CODINGNINJA" ;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (Graph[i][j] == word[0]) {
                
                if (isValid(Graph, n, m, i, j, visited, word, 1)) {   //updated value from 0 to 1, if using updated code, as we need to compare next char from word
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<char>> Graph (n, vector<char>(m));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>Graph[i][j];
        }
    }

     if(hasPath(Graph, n,  m)){
        cout<<1;
     }
     else {
        cout<<0;
     }
    return 0;
}