#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  iota(v.begin(),v.end(),1);
  auto next = v.begin();
  auto end = v.end();
  while(n--){
    auto cur = next + 1;
    if(cur == end) cur = v.begin();
    cout << *cur << " ";
    next = cur + 1;
    if(next == end) next = v.begin();
    end = v.erase(cur);
  }
}
