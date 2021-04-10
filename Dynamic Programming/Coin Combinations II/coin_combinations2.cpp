#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main(){
  int n, target;
  cin >> n >> target;
  vector<int> coins(n);
  for(int i = 1; i <= n; ++i) cin >> coins[i];
  vector<vector<int> > memo(n+1, vector<int>(target+1, 0));
  for(int i = 0; i <= n; ++i) memo[i][0] = 1;
  
  for(int i = 1; i <= n; ++i){
    for(int x = 1; x <= target; ++x){
      memo[i][x] = memo[i-1][x];
      if(coins[i] <= x) memo[i][x] += memo[i][x-coins[i]];
      memo[i][x] = memo[i][x] % mod;
    }
  }

  cout << memo[n][target] << endl;
  return 0;
}
