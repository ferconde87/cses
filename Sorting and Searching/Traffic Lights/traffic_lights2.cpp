#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, n;
  cin >> x >> n;
  multiset<int> m;
  set<int> s;
  m.insert(x);
  s.insert(0);
  s.insert(x);
  for(int i = 0; i < n; ++i){
    int a;
    cin >> a;
    auto it = s.lower_bound(a);
    int r = *it--;
    int l = *it;
    auto itm = m.find(r-l);
    m.erase(itm);
    m.insert(r-a);
    m.insert(a-l);
    s.insert(a);
    cout << *m.rbegin() << " ";
  }
}
