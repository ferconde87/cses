#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n+1);
  iota(v.begin(),v.end(),0);
  for(int x : v) cout << x << " "; cout << endl;
  int i = 1;
  while(n--){
    cout << "n = " << n+1 << endl;
    cout << "i = " << (i%(n+1)) << endl;
    auto it = v.begin()+1+(i%(n+1));
    cout << *it << endl;
    v.erase(it);
    i++;
  }


}
