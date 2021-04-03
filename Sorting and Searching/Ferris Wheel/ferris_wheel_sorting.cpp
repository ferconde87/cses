#include <bits/stdc++.h>
 
using namespace std;
 
int ferris_wheel(vector<int> & p, int x){
  sort(p.begin(), p.end());
  int n = p.size();
  int i = 0;
  int j = n-1;
  int ans = 0;
  int limit = 0;
  int in = 0;
  while(i<=j && limit != x){
    limit = x;
    in = 0;
    while(i < j && limit >= p[j] && in < 2){
      limit-=p[j];
      j--;
      in++;
    }
    while(i <= j && limit >= p[i] && in < 2){
      limit-=p[i];
      i++;
      in++;
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
