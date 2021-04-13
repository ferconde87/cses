
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  multiset<int> s;
  int ans = 0;
  for(int i = 0; i<n; ++i){
    int x;
    cin >> x;
    auto it = s.upper_bound(x);
    if(it != s.end()){
      s.erase(it);
    }
    s.insert(x);
  }

  cout << s.size() << endl;

  return 0;
}
