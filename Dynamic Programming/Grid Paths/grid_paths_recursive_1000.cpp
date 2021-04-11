#include <bits/stdc++.h>

using namespace std;

int memo[1001][1001];
const int mod = 1e9+7;

// void grid_paths(vector<string> & matrix, int i, int j, int n){
//   memo[i][j]++;
//   if(i == n-1 && j == n-1) return;
//   if(i < n-1 && matrix[i+1][j] != '*') grid_paths(matrix, i+1, j, n);
//   if(j < n-1 && matrix[i][j+1] != '*') grid_paths(matrix, i, j+1, n);
// }

void grid_paths(vector<string> & matrix, int n){
  memo[0][0] = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i > 0 && matrix[i-1][j] != '*') memo[i][j] += memo[i-1][j];
      if(j > 0 && matrix[i][j-1] != '*') memo[i][j] += memo[i][j-1];
      memo[i][j] = memo[i][j] % mod;
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<string> matrix(n);
  for(int i = 0; i < n; ++i){
    cin >> matrix[i];
  }
  
  // int n = 1000;
  // vector<string> matrix;
  // for(int i = 0; i < 1000; ++i){
  //   string s(1000,'.');
  //   matrix.push_back(s);
  // }

  grid_paths(matrix, n);
  cout << memo[n-1][n-1] << endl;
}
