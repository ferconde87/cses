#include <bits/stdc++.h>

//TLE

using namespace std;

void sum_of_two_values(vector<int> & v, int obj){
  unordered_set<int> s;
  int n = v.size();
  for(int i = 0; i < n; ++i){
    int x = v[i];
    if(x > obj) continue;
    int y = obj - x;
    if(s.find(y) != s.end()){
      auto it = find(v.begin(), v.end(), y);
      cout << it - v.begin() + 1 << " ";
      cout << i + 1 << endl;
      return;
    }else{
      s.insert(x);
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];

  sum_of_two_values(v, x);

  return 0;
}
