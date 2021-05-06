#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
int main(){
  int n, k;
  cin >> n >> k;
  indexed_set s;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  ll ans = 0;
  for(int i = 0; i < k; ++i) ans+= (n-i);
  int i = 0;
  int j = 0;
  while(i < n && j < n){
    if(s.size() < k){
      s.insert(a[j]);
      ++j;
      if(j-i>k) ans++;
    }else{
      auto it = s.find(a[j]);
      if(it==s.end()){
        auto it2 = s.find_by_order(i);
        s.erase(it2);
        i++;
      }
      s.insert(a[j]);
      ++j;
      if(j-i>k) ans++;
    }
  }
  cout << ans;
}
