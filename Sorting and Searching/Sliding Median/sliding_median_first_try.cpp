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
  for(int i = 0; i < k; ++i){
    int x; cin >> x;
    cout << x << " ";
    s.insert(x);
  }
  int median = k/2;
  cout << "median = " << median << endl;
  cout << *s.find_by_order(median) << " ";
  for(int i = k, j = 0; i < n; ++i, ++j){
    auto it = s.find_by_key(j);
    s.erase(it);
    int x; cin >> x;
    s.insert(x);
    cout << *s.find_by_order(median) << " ";
  }
}
