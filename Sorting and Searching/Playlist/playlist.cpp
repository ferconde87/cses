
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
  int cur = 0;
  for(int i = 0; i<n; ++i){
    int x;
    cin >> x;
    auto it = m.find(x);
    if(it == m.end()){
      cur++;
      m[x] = i;
    }else{
      cur = min(i - it->second, cur+1);
      it->second = i;
    }
    ans = max(ans,cur);
  }

  cout << ans << endl;

  return 0;
}
