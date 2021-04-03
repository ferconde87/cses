#include <bits/stdc++.h>

using namespace std;

int apartments(vector<int> & v, vector<int> & a, int k){
  sort(v.begin(), v.end());
  sort(a.begin(), a.end());
  int i = 0;
  int j = 0;
  int n = v.size();
  int m = a.size();
  int ans = 0;
  while(i < n && j < m){
    if(abs(v[i]-a[j]) <= k){
      ans++;
      i++;
      j++;
    }else if(v[i] < a[j]){
      i++;
    }else{
      j++;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  vector<int> a(m);
  for(int i = 0; i < m; ++i) cin >> a[i];

  cout << apartments(v,a,k) << endl;

  return 0;
}
