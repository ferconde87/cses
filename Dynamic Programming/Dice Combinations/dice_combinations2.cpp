#include <bits/stdc++.h>

using namespace std;

#define ll long long

int const N = 1e6;

int dp[N+1];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int mod = 1e9+7;
  dp[0]=1;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=min(6,i); ++j){
      dp[i]=(dp[i]+dp[i-j])%mod;
    }
  }
  cout << dp[n] << endl;
  
  return 0;
}
