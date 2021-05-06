#include <bits/stdc++.h>

using namespace std;

int n, m;
int const N = 5000;
int dp[N+1][N+1];

int main(){
  string a, b;
  cin >> a >> b;
  n = a.size();
  m = b.size();
  for(int i=1; i<=n; ++i) dp[i][0] = i;
  for(int j=1; j<=m; ++j) dp[0][j] = j;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) +1;   
    }
  }

  cout << dp[n][m];
}
