
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, int> m;
  int ans = 0;
  vector<int> v(n);
  for(int&x:v)cin>>x;
  for(int i = 0, j = 0; i<n; ++i){
    while(j < n && m[v[j]]==0){
      m[v[j]]++;
      ++j;
    }
    ans = max(j - i, ans);
    if(v[i] != v[j-1]) cout << v[i] << " " << v[j-1] << endl; 
    m[v[i]]--;
  }

  cout << ans << endl;

  return 0;
}
