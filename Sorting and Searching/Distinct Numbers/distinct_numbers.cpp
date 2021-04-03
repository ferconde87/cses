#include <bits/stdc++.h>

using namespace std;

int distinct_numbers(vector<int> & v){
  unordered_set<int> s(v.begin(), v.end());
  return s.size();
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];

  cout << distinct_numbers(v) << endl;

  return 0;
}
