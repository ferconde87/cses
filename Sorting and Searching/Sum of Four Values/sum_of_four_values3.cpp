#include <bits/stdc++.h>

using namespace std;

#define ar array

int main(){
  int n, target;
  cin >> n >> target;
  unordered_map<int, ar<int,2> > m;
  vector<int> v(n+1);
  for(int i = 1; i <= n; ++i) cin >> v[i];
  m.reserve(1<<18);//speeding up the unordered_map :-O, now it's OK and it takes 0.02s
  for(int i = 1; i < n; ++i){
    for(int j = i+1; j <= n; ++j){
      int sum = v[i] + v[j];
      auto it = m.find(sum);
      if(it != m.end()){
        auto x = it->second;
        cout << i << " " << j << " " << x[0] << " " << x[1];
        return 0;
      }
    }
    for(int j = 1; j < i; ++j){
      int rem = target - v[i]-v[j];
      m[rem] = {i,j};
    }
  }
  cout << "IMPOSSIBLE";
}
