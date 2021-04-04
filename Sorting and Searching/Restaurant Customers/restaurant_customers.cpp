#include <bits/stdc++.h>

using namespace std;

int restaurant_customers(map<int, int> & in, map<int, int> & out){
  auto itx = in.begin();
  auto ity = out.begin();
  int cur = 0;
  int ans = 0;
  while(itx != in.end() && ity != out.end()){
    if(itx->first == ity->first){
      cur += (itx->second - ity->second);
      itx++;
      ity++;
    }else if(itx->first < ity->first){
      cur += itx->second;
      itx++;
    }else{
      cur -= ity->second;
      ity++;
    } 
    ans = max(ans,cur);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  map<int, int> in, out;
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    in[x]++;
    out[y]++;
  }

  cout << restaurant_customers(in, out) << endl;

  return 0;
}
