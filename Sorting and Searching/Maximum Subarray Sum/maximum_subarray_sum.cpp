
#include <bits/stdc++.h>

using namespace std;

#define ll long long


ll maximum_subarray_sum(vector<ll> & v){
  ll cur = INT_MIN;
  ll ans = cur;
  for(ll x : v){
    cur = max(cur+x,x);
    ans = max(ans,cur);
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

  cout << maximum_subarray_sum(v) << endl;

  return 0;
}
