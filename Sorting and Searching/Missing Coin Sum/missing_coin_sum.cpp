
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll missing_coin_sum(vector<ll> & v){
  sort(v.begin(), v.end());
  ll ans = 1;
  for (int i = 0; i < v.size(); i++){
    if(v[i] <= ans){
      ans += v[i];
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

  cout << missing_coin_sum(v) << endl;


  return 0;
}
