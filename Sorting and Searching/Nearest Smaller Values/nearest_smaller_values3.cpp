#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int a[n+1];
  int nl[n+1];
  cout << 0 << " ";
  cin >> a[0];
  for(int i=2; i<=n; ++i){
    cin >> a[i];
    nl[i]= i-1;
    while(a[nl[i]]>=a[i]){
      nl[i] = nl[nl[i]];
    }
    cout << nl[i] << " ";
  }
}
