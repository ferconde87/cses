#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int mxN=500;
int dp[mxN][mxN*(mxN+1)/2+1];

int main() {
  int n;
  cin >> n;
  int sum=n*(n+1)/2;
  if (sum&1) {
    cout << 0 << endl;
    return 0;
  }
  int target=sum/2;
  dp[0][0] = 1;
  for(int i=1; i<n; ++i){
    for(int j=0; j<=target; ++j) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	      dp[i][j] = (dp[i][j]+dp[i-1][left]) % mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}
