#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n, k;
  cin >> n >> k;
  ll a[n];
  ll sum=0;
  for(int i=0; i<n; ++i) cin >> a[i], sum+=a[i];
  ll obj=sum/k;
  ll cur=0;
  ll windows=0;
  ll ans = 0;
  int i=0;
  for(; i<n; ++i){
    cout << a[i] << " ";
    if(cur+a[i]<=obj){
      cur+=a[i];
    }else{
      cur = 0;
      windows++;
      // cout << windows << endl;
      if(windows==k-1) break;
    }
  }
  cout << i << endl;
  for(int j=i-1; j<n; ++j) ans+=a[j];

  cout << ans << endl;
}
