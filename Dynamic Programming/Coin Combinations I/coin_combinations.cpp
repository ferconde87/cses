#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  const int mod = 1e9+7;
  for(int i = 0; i < n; ++i) cin >> coins[i];
  vector<int> values(x+1,0);
  values[0] = 1;
  for(int i = 1; i <= x; ++i){
    for(int c : coins){
      if(c <= i){
        values[i] += values[i-c];
        values[i] = values[i] % mod;
      }
    }
  }
  cout << values[x] << endl;
  return 0;
}
