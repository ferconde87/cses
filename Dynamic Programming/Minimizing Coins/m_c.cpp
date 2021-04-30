#include <bits/stdc++.h>

using namespace std;

int const lim = 1e9;

int main(){
  int n, target;
  cin >> n >> target;
  int coins[n];
  for(int i=0; i<n; ++i) cin >> coins[i];
  int dp[target+1];
  dp[0]=0;
  for(int x=1; x<=target; ++x){
    dp[x]=lim;
    for(int c : coins){
      if(c<=x){
        dp[x]=min(dp[x],dp[x-c]+1);
      }
    }
  }
  if(dp[target]==lim) cout << -1;
  else cout << dp[target];
}
