
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

ll diff(vector<ll> & v, ll obj){
  ll ans = 0;
  for(ll x : v) ans += abs(x-obj);
  return ans;
}

ll stick_lengths(vector<ll> & v){
  ll sum = 0;
  for(ll x : v) sum += x;
  int n = v.size();
  double prom = sum / (double)n;
  // double x = sum / n;
  // ll obj = 0;
  // if((prom - x) > 0.5){
  //   obj = ceil(prom);
  // }else{
  //   obj = floor(prom);
  // }
  ll r = diff(v,floor(prom));
  ll l = diff(v,ceil(prom));
  return min(l,r);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];

  cout << stick_lengths(v) << endl;

  return 0;
}
