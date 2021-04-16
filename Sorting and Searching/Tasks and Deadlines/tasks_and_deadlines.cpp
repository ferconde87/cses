#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ar array

int main(){
  int n;
  cin >> n;
  ar<ll,2> a[n];
  for(int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
  sort(a,a+n);
  ll ans = 0;
  ll time = 0;
  for(int i = 0; i < n; ++i){
    time += a[i][0];
    ans += a[i][1] - time;
  }
  cout << ans;
}
