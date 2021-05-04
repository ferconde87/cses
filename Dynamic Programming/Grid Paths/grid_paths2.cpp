#include <bits/stdc++.h>

using namespace std;

int memo[1000][1000];
const int mod = 1e9+7;

void grid_paths(vector<string> & matrix, int n){

  memo[0][0] = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(matrix[i][j]=='*') continue;
      if(i) memo[i][j] += memo[i-1][j];
      if(j) memo[i][j] += memo[i][j-1];
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
  if(matrix[0][0] != '*' && matrix[n-1][n-1] != '*') grid_paths(matrix, n);
  cout << memo[n-1][n-1] << endl;
}
