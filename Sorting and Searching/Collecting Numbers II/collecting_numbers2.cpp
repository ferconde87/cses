#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  unordered_set<int> s;
  vector<int> p(n+1);
  vector<int> v(n+1);
  p[0] = 0;
  v[0] = 0;
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    p[x] = i;
    if(x==1){
      ans++;
    }else{
      auto it = s.find(x-1);
      if(it==s.end()) ans++;
    }
    s.insert(x); 
  }

  while(m--){
    int a, b;
    cin >> a >> b;
    int x = v[a]-1;
    int y = v[b]-1;
    if(p[x] < a && p[x] > b) ans++;
    if(p[x] > p[a] && p[x] < p[b]) ans--;
    if(p[y] < p[b] && p[y] > p[a]) ans++;
    if(p[y] > p[b] && p[y] < p[a]) ans--;
    
    int elem = v[a];
    int pos_elem = p[elem];
    v[a] = v[b];
    p[a] = p[b];
    v[b] = elem;
    p[b] = pos_elem;

    cout << ans << endl;
  }

  return 0;
}
