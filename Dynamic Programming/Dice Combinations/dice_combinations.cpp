#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int mod = 1e9+7;
  vector<int> count(n+1);
  for(int i = 1; i <= 6; ++i) count[i] = pow(2,i-1);
  for(int i = 7; i <= n; ++i){
    for(int j = 1; j <= 6; j++){
      count[i] += count[i-j];
      count[i] = count[i] % mod;
    }
  }

  cout << count[n] << endl;
  
  return 0;
}
