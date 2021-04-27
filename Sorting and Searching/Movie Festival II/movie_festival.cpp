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
  int ans = 0;
  int count = 0;
  for(int i = 0; i < n; ++i){
      auto it = s.lower_bound(a[i][1]+1);
      if(it == s.begin()){
        if(count < k){
          s[a[i][0]]++;
          count++;
          ans++;
        }
      }else{
        --it;
        it->second--;
        if(it->second == 0) s.erase(it);
        s[a[i][0]]++;
        ans++;
      }    
  }
  cout << ans << endl;
}
