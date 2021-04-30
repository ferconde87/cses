#include <bits/stdc++.h>

using namespace std;

int const lim = 1e9+7;

int main(){
  int n, target;
  cin >> n >> target;
  int coins[n];
  for(int i=0; i<n; ++i) cin >> coins[i];
  int dp[target+1];
  dp[0]=1;
  for(int x=1; x<=target; ++x){
    dp[x]=0;
    for(int c : coins){
      if(c<=x){
        dp[x]+=dp[x-c];
        dp[x]=dp[x]%lim;
      }
    }
  }
  cout << dp[target];
}
