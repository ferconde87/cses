#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  ll a, b;
  cin >> n >> a >> b;
  ll sum[n+1];
  for(int i=1; i<=n; ++i){
    cin >> sum[i];
    sum[i]+=sum[i-1];
  } 
  multiset<ll> s;
  ll ans=LONG_LONG_MIN;
  for(int i=a; i<=n; ++i){
    s.insert(sum[i-a]);
    ans=max(sum[i]-*s.begin(),ans);
    if(i>=b){
      auto it = s.find(sum[i-b]);
      s.erase(it);
    }
  }
  cout << ans << endl;
}
