//矩阵中路径（回溯法）
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>>& board, string word, int row, int col, int count);
bool exist(vector<vector<char>>& board, string word);
int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    cout<<"res="<<exist(board,word)<<endl;
    return 0;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0;i < board.size();i++) {
        for (int j = 0;j < board[0].size();j++) {
            if (dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
bool dfs(vector<vector<char>>& board, string word, int row, int col, int count) {
    if (word == "\0") return true;
    //y越界处理和mismatch处理
    if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || board[row][col] != word[count]) return false;
    //说明已经匹配到了
    if (count == word.size() - 1) return true;
    board[row][col] = '\0';//已经遍历过的设置为'\0'保证为false
    bool res = dfs(board, word, row, col + 1, count + 1) || dfs(board, word, row + 1, col, count + 1)
        || dfs(board, word, row - 1, col, count + 1) || dfs(board, word, row, col - 1, count + 1);
    board[row][col] = word[count];//还原
    return res;
}
