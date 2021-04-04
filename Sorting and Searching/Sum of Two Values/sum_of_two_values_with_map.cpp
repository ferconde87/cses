
#include <bits/stdc++.h>


using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  map<int, int> m;
  for(int i = 1; i <= n; ++i){
    int a;
    cin >> a;
    if(a >= x) continue;
    int y = x - a;
    auto it = m.find(y);
    if(it != m.end()){
      cout << it->second << " " << i << endl;
      return 0;
    }
    m[a] = i;
  }
  cout << "IMPOSSIBLE\n"; 

  return 0;
}
