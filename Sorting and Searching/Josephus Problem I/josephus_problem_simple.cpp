#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
  int n;
  cin >> n;
  indexed_set s;
  for(int i = 1; i <= n; ++i) s.insert(i);
  int i = 0;
  while(n){
    i = (i + 1) % n;
    auto it = s.find_by_order(i);
    cout << *it  << " ";
    s.erase(it);
    --n;
  }
}
