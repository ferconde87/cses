#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  ll x, y;
  cin >> n >> x >> y;
  ll a[n+1];
  ll sum[n+1];
  for(int i=1; i<=n; ++i) cin >> a[i];
  sum[1]=a[1];
  multiset<ll> s;
  ll ans=INT_MIN;
  for(int i=2; i<=n; ++i) sum[i]=sum[i-1]+a[i];

  for(int i=1; i<=n; ++i) cout << sum[i] << " "; cout << endl;

  for(int i=x; i<y; ++i) s.insert(sum[i]);
  for(int i=0; i<n-x; ++i){
    cout << a[i+y] << endl;
    if(i+y < n) s.insert(sum[i+y]);
    cout << "size =" << s.size() << endl;
    ll top = *--s.end();
    ll cur= (i==0) ? top : top-sum[i-1];
    cout << "cur = " << cur << endl;
    ans=max(ans,cur);
    auto it=s.find(sum[i+x]);
    s.erase(it);
  }
  cout << ans << endl;
}
