#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int main(){
  int a, b;
  cin >> a >> b;
  for(int i=1; i<=a; ++i) dp[i][1]=i-1;
  for(int j=1; j<=b; ++j) dp[1][j]=j-1;
  for(int i=2; i<=a; ++i){
    for(int j=2; j<=b; ++j){
      if(i == j) continue;
      dp[i][j] = 1001;
      for(int r=1; r<i; ++r){
        int k=i-r;
        dp[i][j]=min(dp[i][j],dp[k][j]+dp[r][j]+1);
      }
      for(int c=1; c<j; ++c){
        int k=j-c;
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][c]+1);
      }
    }
  }
  cout << dp[a][b];
}
