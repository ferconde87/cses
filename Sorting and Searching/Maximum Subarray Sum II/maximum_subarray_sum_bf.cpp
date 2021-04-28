#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  ll x, y;
  cin >> n >> x >> y;
  ll a[n];
  ll sum[n];
  for(int i=0; i<n; ++i) cin >> a[i];
  sum[0]=a[0];
  ll ans=INT_MIN;
  for(int i=1; i<n; ++i) sum[i]=sum[i-1]+a[i];
  for(int i=0; i<n; ++i){
    ll cur = 0;
    for(int j=i+x; j<n && j<=i+y; ++j){
      cur=(i==0) ? sum[j] : sum[j]-sum[i-1];
      ans=max(ans,cur);
    }
  }
  cout << ans << endl;
}
