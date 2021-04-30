#include <bits/stdc++.h>

using namespace std;

int const lim = 1e9+7;
int const N = 1e6+1;
int dp[N];

int main(){
  int n, target;
  cin >> n >> target;
  int coins[n];
  for(int i=0; i<n; ++i) cin >> coins[i];
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
