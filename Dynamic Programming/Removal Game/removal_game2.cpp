#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=5e3;
ar<ll,2> dp[mxN][mxN];
int n, x[mxN];

int main(){
  cin >> n;
  for(int i=0; i<n; ++i) cin >> x[i];
  for(int i=0; i<n; ++i){
    for(int j=i; j>=0; --j){
      ar<ll,2> tr;
      if(i==j)
        tr={x[i],0};
      else {
        if(dp[i-1][j][1]+x[i]>dp[i][j+1][1]+x[j])
          tr={dp[i-1][j][1]+x[i],dp[i-1][j][0]};
        else
          tr={dp[i][j+1][1]+x[j],dp[i][j+1][0]};
      }
      dp[i][j]=tr;
    }
  }
  cout << dp[n-1][0][0];
}
