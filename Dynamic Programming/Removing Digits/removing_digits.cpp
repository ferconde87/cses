#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 10, j = 0; i <= 1000000; i*=10, ++j) v[j] = i;
  int ans = 0;
  int max = 0;
  while(n){
    int m = n;
    for(int i = 5; i >= 0; --i){
      int cur = m / v[i];
      if(cur > max){
        max = cur;
      }
      m -= cur*v[i];
    }
    int rem = m % 10;
    if(rem > max) max = rem;
    n-= max;
    ans++;
    max = 0;
  }
  cout << ans << endl;
}
