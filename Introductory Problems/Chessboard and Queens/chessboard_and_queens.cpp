#include <bits/stdc++.h>

using namespace std;

int result = 0;

void chessboard_and_queens(vector<string> & board, vector<bool> col, vector<bool> d1, vector<bool> d2, int r){
  if(r == 8){
    result++;
    return;
  }

  for(int c = 0; c < 8; ++c){
    if(board[r][c] == '*') continue;
    if(!col[c] && !d1[c+r] && !d2[8-r+c]){
      col[c] = true;
      d1[c+r] = true;
      d2[8-r+c] = true;
      chessboard_and_queens(board, col, d1, d2, r+1);
      col[c] = false;
      d1[c+r] = false;
      d2[8-r+c] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> board(8);
  for(int i = 0; i < 8; ++i) cin >> board[i];

  vector<bool> col(8, false);
  vector<bool> d1(15, false);
  vector<bool> d2(15, false);

  chessboard_and_queens(board, col, d1, d2, 0);

  cout << result << endl;

  return 0;
}
