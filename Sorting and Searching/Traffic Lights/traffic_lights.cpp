#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, n;
  cin >> x >> n;
  map<int, int> m;
  set<int> s;
  m[x] = 1;
  s.insert(0);
  s.insert(x);
  for(int i = 0; i < n; ++i){
    int a;
    cin >> a;
    auto it = s.lower_bound(a);
    int r = *it--;
    int l = *it;
    m[r-l]--;
    if(m[r-l]==0) m.erase(r-l);
    m[r-a]++;
    m[a-l]++;
    s.insert(a);
    cout << m.rbegin()->first << " ";
  }
}
