#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int ans = 0;
vector<int> col(8, -1);
vector<int> diag1(16, -1);
vector<int> diag2(16, -1);
vector<vector<char>> board(8, vector<char>(8));

void search(int y){
    if(y == 8){
        ans++;
        return;
    }
    for(int x = 0; x < 8; x++){
        if(col[x] != -1 || diag1[x+y] != -1 || diag2[x-y+7] != -1 || board[y][x] == '*'){
            continue;
        }
        col[x] = diag1[x+y] = diag2[x-y+7] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+7] = -1;
    }

}
int main (){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin>>board[i][j];
        }
    }
    search(0);
    cout<<ans<<endl;
    return 0;
}




