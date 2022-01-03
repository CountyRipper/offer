//机器人在矩阵中可以到达的格子数目
//典型的DFS+回溯，DFS所到之处都为答案
#include<bits/stdc++.h>
using namespace std;
int movingCount(int m, int n, int k);
int dfs(int threshold, vector<vector<bool>> &matrix, int row, int col);
int main(){
    int m =10, n =5, k = 3;
    cout<<"answer= "<<movingCount(m,n,k)<<endl;
}
int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        vector<vector<bool>> matrix(m, vector<bool>(n,false));
        return dfs(k,matrix,0,0);
    }
int dfs(int threshold, vector<vector<bool>> &matrix, int row, int col){
        if(row<0||row>=matrix.size()||col<0||col>=matrix[row].size()||((col%10+col/10+row%10+row/10)>threshold)||matrix[row][col]) return 0;
        matrix[row][col]=true;//已经visited过了
        return (dfs(threshold ,matrix,row,col-1)+dfs(threshold ,matrix,row-1,col)+dfs(threshold ,matrix,row+1,col)+dfs(threshold ,matrix,row,col+1))+1;
    }