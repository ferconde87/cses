#include <bits/stdc++.h>

using namespace std;

int const lim = 1e9+7;

int main(){
  int n, target;
  cin >> n >> target;
  int coins[n];
  for(int i=0; i<n; ++i) cin >> coins[i];
  sort(coins,coins+n);
  int dp[target+1];
  for(int i=1; i<=target; ++i) dp[i]=0;
  dp[0]=1;
  for(int c : coins){
    for(int x=1; x<=target; ++x){
      if(c<=x){
        dp[x]+=dp[x-c];
        dp[x]=dp[x]%lim;
      }
    }
  }
  cout << dp[target];
}
