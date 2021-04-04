#include <bits/stdc++.h>

// "You may assume that all arrival and leaving times are distinct."

using namespace std;

int restaurant_customers(vector<int> & in, vector<int> & out){
  sort(in.begin(), in.end());
  sort(out.begin(), out.end());
  int ans = 0, cur = 0, n = in.size();
  for(int i = 0, j = 0; i < n && j < n; ){
    if(in[i] < out[j]){
      cur++;
      i++;
      ans = max(ans,cur);
    }else{
      cur--;
      j++;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> in(n), out(n);

  for(int i = 0; i < n; ++i){
    cin >> in[i] >> out[i];
  }

  cout << restaurant_customers(in, out) << endl;

  return 0;
}
