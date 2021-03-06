#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
  int n;
  cin >> n;
  for(int i = 2; i <= n; i+=2) cout << i << " ";
  int m = n/2;
  m += (n % 2) ? 1 : 0;
  indexed_set s;
  for(int i = 1, j = 0; j < m; i+=2, ++j) s.insert(i);
  int i = (n % 2) ? -1 : 0;
  while(m){
    i = (i + 1) % m;
    auto it = s.find_by_order(i);
    cout << *it  << " ";
    s.erase(it);
    --m;
  }
}
