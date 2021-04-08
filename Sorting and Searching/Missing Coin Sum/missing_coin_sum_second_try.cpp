
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

const int N = 2*1e5;
bool ok[10*N];
vector<bool> sums[10*N];

ll missing_coin_sum(vector<int> & v){
  int n = v.size();
  sort(v.begin(), v.end());
  ok[0] = true;
  int ans = 0;
  int i = 0;

  //opt
  for(int i = 0; i < n; ++i){
    int x = v[i];
    sums[x].resize(n);
    sums[x][i] = true;
    ok[x] = true;
  }


  for(ll x = 1; ; ++x){
    if(ok[x]) continue;
    for(int i = n-1; i >= 0; --i){
      if(v[i] > x) continue;
      if(!sums[x-v[i]].empty() && sums[x-v[i]][i]) continue;
      if(ok[x-v[i]]){ 
        if(sums[x-v[i]].empty()) sums[x-v[i]].resize(n); 
        ok[x] = true;
        sums[x] = sums[x-v[i]];
        sums[x][i] = true;
        break;
      }
    }
    // cout << "x = " << x << endl;
    if(!ok[x]) return x;
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
  // int n = 1000;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  // v[50] = 10000;
  // for(int x : v) cout << x << " "; cout << endl;

  // cout << n << " " << v[0] << endl;

  cout << missing_coin_sum(v) << endl;

  return 0;
}
