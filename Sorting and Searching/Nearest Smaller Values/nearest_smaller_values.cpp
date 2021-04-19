#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  map<int, int> m;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    auto it = m.lower_bound(x);
    if(it == m.begin()){
      cout << 0 << " ";
      m = {};
    }else if(it != m.end()){
      auto cur = it;
      cout << (--cur)->second << " ";
      m.erase(it, m.end());
    }else{
      cout << (--it)->second << " ";
    }
    m[x] = i;
  }
}
