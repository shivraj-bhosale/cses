#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int n,int m,int i,int j,vector<string>&grid){
    if(grid[i][j]=='#') return;
    grid[i][j]='#';
    if(i-1>=0) dfs(n,m,i-1,j,grid);
    if(i+1<n) dfs(n,m,i+1,j,grid);
    if(j-1>=0) dfs(n,m,i,j-1,grid);
    if(j+1<m) dfs(n,m,i,j+1,grid);    
}

int main(){
    int n,m,answer=0;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                answer++;
                dfs(n,m,i,j,grid);
            }
        }
    }
    cout<<answer;
}

// intution -> language of question is not on point, once you see test case and imagine,
// grid as top view of a single level of building then it's easy.

// solution -> count total number of connected '.', because '.' is a floor and 
// coonected '.' form a room as there is no wall seperating them,





// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1<=n,m<=1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3