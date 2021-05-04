#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  int max_value = 0;
  while(n){
    int m = n;
    while(m){
      max_value = max(max_value,m%10);
      m/=10;
    }
    n-= max_value;
    ans++;
    max_value = 0;
  }
  cout << ans << endl;
}
