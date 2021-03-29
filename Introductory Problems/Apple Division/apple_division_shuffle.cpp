#include <bits/stdc++.h>

using namespace std;

long long apple_division(vector<long long> v){
  long long result = LONG_LONG_MAX;
  int n = v.size();
  if(n == 1) return v[0];
  vector<long long> sum(n, 0);
  vector<long long> ans;
  for(int i = 0; i < 500000; ++i){
    random_shuffle(v.begin(), v.end());
    sum[0] = v[0];
    for(int i = 1; i < n; ++i) sum[i] = sum[i-1] + v[i];
    for(int i = 1; i < n; ++i){
      long long diff = abs(sum[n-1] - 2*sum[i-1]);
      if(diff < result){
        result = diff;
        ans = v;
      } 
    } 
  }
  return result;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];

  cout << apple_division(v) << endl;

  return 0;
}
