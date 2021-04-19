#include <bits/stdc++.h>

using namespace std;

#define ar array

//note: if we use unordered_map instead of map, we get LTE over here :P

int main(){
  int n, target;
  cin >> n >> target;
  map<int, ar<int,2> > m;
  vector<int> v(n+1);
  for(int i = 1; i <= n; ++i) cin >> v[i];

  for(int i = 1; i < n; ++i){
    for(int j = i+1; j <= n; ++j){
      int sum = v[i] + v[j];
      if(sum >= target) continue;
      auto it = m.find(sum);
      if(it != m.end()){
        auto x = it->second;
        if(x[0]!=i && x[0] !=j && x[1]!=i && x[1]!=j){
          cout << i << " " << j << " " << x[0] << " " << x[1];
          return 0;
        }
      }
      int rem = target - sum;
      m[rem] = {i,j};
    }
  }
  cout << "IMPOSSIBLE";
}
