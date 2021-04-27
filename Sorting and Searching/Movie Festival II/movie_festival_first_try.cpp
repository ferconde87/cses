#include <bits/stdc++.h>
 
using namespace std;
 
#define ar array
 
int main(){
  int n, k;
  cin >> n >> k;
  ar<int, 2> a[n];
  for(int i = 0; i < n; ++i) cin >> a[i][1] >> a[i][0];
  sort(a,a+n);
  map<int, int> s;
  for(int i = 0; i < k; ++i){
    s[a[i][0]]++;
  }
  int ans = k;
  for(int i = k; i < n; ++i){
    auto it = s.upper_bound(a[i][1]);
    if(it==s.begin()) continue;
    --it;
    it->second--;
    if(it->second == 0) s.erase(it);
    s[a[i][0]]++;
    ans++;
  }
  cout << ans << endl;
}
