#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, target;
  cin >> n >> target;
  unordered_map<int, vector<int> > m;
  vector<int> v(n+1);
  for(int i = 1; i <= n; ++i) cin>>v[i];
  
  for(int i = 1; i <= n; ++i){
    if(m[target-v[i]].size() < 3) 
      m[target-v[i]].push_back(i); 
  }
  
  for(int i=1; i<=n-1; ++i){
    for(int j=i+1; j<=n; ++j){
      int sum = v[i]+v[j];
      auto it = m.find(sum);
      if(it==m.end())continue;
      for(int x : it->second){
        if(i != x && j != x){
          cout << i << " " << j << " " << x << endl;
          return 0;
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";
}
