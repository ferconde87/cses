#include <bits/stdc++.h>

using namespace std;

int ferris_wheel(multiset<int> & s, int x){
  int ans = 0;
  int limit = x;
  bool ok = true;
  int in = 0;
  while(ok){
    auto it = s.lower_bound(limit);

    if(in == 2){
      ans++;
      in = 0;
      limit = x;
    }

    if(it == s.begin() && it == s.end()){
      if(x > limit) ans++;
      return ans;
    } 

    if(it == s.begin() && *it > limit){
      if(limit == x) return ans;
      ans++;
      limit = x;
      continue;
    }

    while(it == s.end() || *it > limit) --it;
    in++;
    limit -= *it;
    s.erase(it);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  multiset<int> s;
  for(int i = 0; i < n; ++i){
    int cur;
    cin >> cur;
    s.insert(cur);
  }

  cout << ferris_wheel(s,x) << endl;

  return 0;
}
