#include <bits/stdc++.h>

using namespace std;

//OK printing first all the evens

int main(){
  int n;
  cin >> n;
  for(int i = 2; i <= n; i+=2) cout << i << " ";
  int m = n/2;
  m += (n % 2) ? 1 : 0;
  vector<int> v(m);
  for(int i = 1, j = 0; j < m; i+=2, ++j) v[j] = i;
  int i = (n % 2) ? -1 : 0;
  while(m){
    i = (i + 1) % m;
    cout << v[i] << " ";
    v.erase(v.begin()+i);
    --m;
  }
}
