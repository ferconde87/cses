#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e5, mxM=100, M=1e9+7;
int n, m, a[mxN];
ll dp[mxN][mxM+1];

int main(){
  cin >> n >> m;
  for(int i=0; i<n; ++i) cin >> a[i];
  if(a[0]==0)
    for(int i=1; i<=m; ++i) dp[0][i]=1;
  else dp[0][a[0]]=1;
  for(int i=1; i<n; ++i){
    if(a[i]==0){
      for(int j=1; j<=m; ++j){
        if(dp[i-1][j]>0){
          dp[i][j]+=dp[i-1][j];
          if(j>1) dp[i][j-1]+=dp[i-1][j];
          if(j<m) dp[i][j+1]+=dp[i-1][j];
          dp[i][j]%=M;
        }
      }
    }else{
      dp[i][a[i]]=dp[i-1][a[i]];
      if(a[i]>1) dp[i][a[i]]+=dp[i-1][a[i]-1];
      if(a[i]<m) dp[i][a[i]]+=dp[i-1][a[i]+1];
      dp[i][a[i]]%=M;
    }
  }
  ll ans=0;
  if(a[n-1]==0){
    for(int j=1; j<=m; ++j){
      ans+=dp[n-1][j];
      ans%=M;
    }
    cout << ans;
  } 
  else cout << dp[n-1][a[n-1]];
}
