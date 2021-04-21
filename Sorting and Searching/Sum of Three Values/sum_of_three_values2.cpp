#include <bits/stdc++.h>

using namespace std;

#define ar array

int main(){
  int n, target;
  cin >> n >> target;
  ar<int, 2> a[n+1];
  for(int i = 1; i <= n; ++i){
    cin >> a[i][0], a[i][1] = i;
  }
  sort(a+1,a+n+1);
  for(int i = 1; i <= n; ++i){
    int rem = target - a[i][0];
    for(int j = i+1, k = n; j < k; ++j){
      while(j < k && a[j][0]+a[k][0] > rem) --k;
      if(j < k && a[j][0]+a[k][0] == rem){
        cout << a[i][1] << " " << a[j][1] << " " << a[k][1];
        return 0; 
      }
    }
  }
  cout << "IMPOSSIBLE";
}
