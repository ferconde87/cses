#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void grid_paths(int i, int j, string path, vector<vector<bool> > memo){
  if(i == 6 && j == 6){
    if(path.size() == 48){
      ans++;
      cout << ans << " ";
    }
    return;
  }

  if(i > 0 && !memo[i-1][j]) {
    memo[i-1][j] = true;
    grid_paths(i-1, j, path+'U', memo);
    memo[i-1][j] = false;
  }

  if(i < 6 && !memo[i+1][j]) {
    memo[i+1][j] = true;
    grid_paths(i+1, j, path+'D', memo);
    memo[i+1][j] = false;
  }

  if(j > 0 && !memo[i][j-1]) {
    memo[i][j-1] = true;
    grid_paths(i, j-1, path+'L', memo);
    memo[i][j-1] = false;
  }

  if(j < 6 && !memo[i][j+1]) {
    memo[i][j+1] = true;
    grid_paths(i, j+1, path+'R', memo);
    memo[i][j+1] = false;
  }


}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // long long k;
  // cin >> k;
  vector<vector<bool> > memo(7, vector<bool>(7,false));
  memo[0][0] = true;
  grid_paths(0,0,"",memo);

  cout << ans << endl;

  return 0;
}
