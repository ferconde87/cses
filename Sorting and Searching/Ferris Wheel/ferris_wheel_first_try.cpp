#include <bits/stdc++.h>

using namespace std;

int ferris_wheel(vector<int> & p, int x){
  sort(p.begin(), p.end());
  int n = p.size();
  int i = 0;
  int j = n-1;
  int ans = 0;
  int limit = 0;
  while(i<=j && limit != x){
    limit = x;
    while(i < j && limit >= p[j]){
      limit-=p[j];
      j--;
    }
    while(i <= j && limit >= p[i]){
      limit-=p[i];
      i++;
    }
    ans++;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> p(n);
  for(int i = 0; i < n; ++i) cin >> p[i];

  cout << ferris_wheel(p,x) << endl;

  return 0;
}
