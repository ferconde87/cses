
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

int missing_coin_sum(vector<int> & v){
  int n = v.size();
  sort(v.begin(), v.end());
  int ans = 1;
  for(int x = 1; x < 1 << 30; ++x){
    int cur = 0;
    for(int i = 0; i < 31; ++i){
      if(x >> i & 1){
        cur += v[i];
      }
    }
    // cout << cur << " ";
    if(cur == ans) ans++;
    else if(cur < ans) continue;
    else return ans;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int n;
  // cin >> n;
  // vector<int> v(n);
  // for(int i = 0; i < n; ++i) cin >> v[i];

  int n = 2*1e5;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  // for(int x : v) cout << x << " "; cout << endl;

  cout << n << " " << v[0] << endl;

  cout << missing_coin_sum(v) << endl;

  return 0;
}
