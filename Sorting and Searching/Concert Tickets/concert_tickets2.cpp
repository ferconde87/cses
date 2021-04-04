#include <bits/stdc++.h>

using namespace std;

void concert_tickets(multiset<int> & s, vector<int> & v){
  for(int x : v){
    auto it = s.upper_bound(x);
    if(it == s.begin()){
      cout << -1 << endl;
      continue;
    }else{
      --it;
      cout << *it << endl;
      s.erase(it);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  multiset<int> s;
  for(int i = 0; i < n; ++i){
    int cur;
    cin >> cur;
    s.insert(cur);
  }
  vector<int> v(m);
  for(int i = 0; i < m; ++i) cin >> v[i];

  concert_tickets(s,v);

  return 0;
}
