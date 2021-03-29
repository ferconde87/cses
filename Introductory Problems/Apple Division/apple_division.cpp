#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll apple_division(vector<ll> & v){
  int n = v.size();
  ll ans = LONG_LONG_MAX;
  ll sum = 0;
  for(int i = 0; i < n; ++i) sum += v[i];
  for(int x = 0; x < 1 << n; ++x){
    ll cur = 0;
    for(int i = 0; i < n; ++i){
      if(x >> i & 1)
        cur += v[i];
    }
    ll diff = abs(sum - 2*cur);
    if(diff < ans){
      ans = diff;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];

  cout << apple_division(v) << endl;
  
  return 0;
}
