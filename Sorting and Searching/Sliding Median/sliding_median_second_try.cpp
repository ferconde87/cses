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
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  indexed_set s;
  for(int i = 0; i < k; ++i){
    s.insert(a[i]);
  }
  int median = k/2;
  cout << s.size() << " ";
  // cout << *s.find_by_order(median) << " ";
  for(int i = k, j = 0; i < n; ++i, ++j){
    auto pos = s.order_of_key(a[j]);
    s.erase(pos);
    cout << s.size() << " ";
    // int x; cin >> x;
    s.insert(a[i]);
    // cout << *s.find_by_order(median) << " ";
  }
}
