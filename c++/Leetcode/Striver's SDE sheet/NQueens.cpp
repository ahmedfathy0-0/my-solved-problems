#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> columns;
    vector<int> diag1;
    vector<int> diag2;
    vector<vector<string>> solveNQueens(int n) {
        columns.resize(n,0);
        diag1.resize(2*n,0);
        diag2.resize(2*n,0);
        vector<vector<string>> ans;
        ///create empty board depending on n
        vector<string> board(n, string(n, '.'));
        search(0, n, ans, board);

        return ans;
    }
    void search(int y, int n, vector<vector<string>>& ans, vector<string> board){
        if(y==n){
            ans.push_back(board);
            return;
        }
        for (int x = 0; x < n; x++){
            if(columns[x] || diag1[x+y] || diag2[x-y+n-1]){
                continue;
            }
            columns[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
            board[y][x] = 'Q';
            search(y+1, n, ans,board);
            columns[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
            board[y][x] = '.';
        }
    }
};

int main (){
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}