#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int dp[n+1];
  dp[0]=0;
  for(int i=1; i<=n; ++i){
    dp[i]=1e9;
    int j=i;
    while(j){
      dp[i]=min(dp[i],dp[i-(j%10)]+1);
      j/=10;
    }
  }
  cout << dp[n];
}
