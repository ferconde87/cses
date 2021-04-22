#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, target;
  cin >> n >> target;
  unordered_map<int, int > m;
  m.reserve(1<<18);
  vector<int> v(n+1);
  for(int i = 1; i <= n; ++i) cin>>v[i];
  
  for(int i = 1; i <= n; ++i){
      m[target-v[i]] = i;
  }
  
  for(int i=1; i<=n-1; ++i){
    for(int j=i+1; j<=n; ++j){
      int sum = v[i]+v[j];
      auto it = m.find(sum);
      if(it==m.end())continue;
      int x = it->second;
      if(i != x && j != x){
        cout << i << " " << j << " " << x;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

