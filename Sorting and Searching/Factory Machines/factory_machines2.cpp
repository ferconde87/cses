#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  ll target;
  cin >> n >> target;
  vector<ll> machines(n);
  for(ll&x:machines) cin >> x;
  ll minv = *min_element(machines.begin(), machines.end());
  ll r = minv*target;
  ll l = 0;
  while(l < r){
    ll mid = (l+r) / 2;
    ll cur = 0;
    for(int m : machines){
      cur += mid/m;
    }
    if(cur >= target) {
      r = mid;
    } else {
      l = mid+1;
    } 
  }
  cout << l << endl;
}
