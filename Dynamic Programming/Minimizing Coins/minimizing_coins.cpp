
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  vector<int> dp(x+1,1e9);
  dp[0] = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= x; ++j){
      if(v[i] <= j){
        dp[j] = min(dp[j], dp[j-v[i]]+1);
      }
    }
  }
  if(dp[x] == 1e9) cout << -1 << endl;
  else cout << dp[x] << endl;  
  return 0;
}
