#include <bits/stdc++.h>

// "You may assume that all arrival and leaving times are distinct."

using namespace std;

int restaurant_customers(multiset<int> & in, multiset<int> & out){
  auto itx = in.begin();
  auto ity = out.begin();
  int cur = 0;
  int ans = 0;
  while(itx != in.end() && ity != out.end()){
    if(*itx < *ity){
      cur++;
      itx++;
      ans = max(ans,cur);
    }else{
      cur--;
      ity++;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  multiset<int> in, out;
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    in.insert(x);
    out.insert(y);
  }

  cout << restaurant_customers(in, out) << endl;

  return 0;
}
