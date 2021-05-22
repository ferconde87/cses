#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=500, M=1e9+7;  
ll dp[mxN*(mxN+1)/2+1];

int main(){
  int n;
  cin >> n;
  int sum = n*(n+1)/2;
  if(sum&1){
    cout << 0;
    return 0;
  }
  int target=sum/2;
  dp[0]=1;
  for(int i=1; i<=n; ++i){
    for(int j=i*(i+1)/2; j>=i; --j){
      dp[j]=(dp[j]+dp[j-i])%M;
    }
  }
  cout << dp[target]*((M+1)/2)%M;
}
