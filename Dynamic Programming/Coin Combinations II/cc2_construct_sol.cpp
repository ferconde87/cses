#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main(){
  int n, target;
  cin >> n >> target;
  vector<int> coins(n+1);
  for(int i = 1; i <= n; ++i) cin >> coins[i];
  vector<vector<int> > memo[n+1][target+1];
  sort(coins.begin(), coins.end());
  for(int i = 0; i <= n; ++i) memo[i][0].push_back(vector<int>());
  
  for(int i = 1; i <= n; ++i){
    for(int x = 1; x <= target; ++x){
      memo[i][x] = memo[i-1][x];
      if(coins[i] <= x){
        for(auto v : memo[i][x-coins[i]]){
          vector<int> cur = v;
          cur.push_back(coins[i]);
          memo[i][x].push_back(cur);
        }
      } 
    }
  }

  for(auto v : memo[n][target]){
    for(int c : v) cout << c << " ";
    cout << endl;
  }

  return 0;
}
