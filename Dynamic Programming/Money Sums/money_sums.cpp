#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
bool dp[N];

int main(){
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  for(int i=0; i<n; ++i) cin >> a[i], sum+=a[i];
  dp[0]=true;
  int ans=0;
  for(int i=0; i<n; ++i){
    for(int j=sum; j>=1; --j){
      if(a[i]<=j&&dp[j-a[i]]){
        if(dp[j]) continue;
        dp[j]=true;
        ++ans;
      }
    }
  }
  cout << ans << endl;
  for(int i=1; i<=sum; ++i)
    if(dp[i])
      cout << i << " ";
}
