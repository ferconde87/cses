
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

ll stick_lengths(vector<ll> & v){
  int n = v.size();
  sort(v.begin(), v.end());
  ll median = v[n/2];
  ll ans = 0;
  for(ll x : v){
    ans += abs(x-median);
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

  cout << stick_lengths(v) << endl;

  return 0;
}
