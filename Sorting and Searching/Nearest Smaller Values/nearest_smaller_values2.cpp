#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int a[n+1];
  int nl[n+1];
  for(int i=0; i<n; ++i){
    cin >> a[i];
    nl[i]=i-1;
    while(~nl[i]&&(a[nl[i]]>=a[i])){
      nl[i] = nl[nl[i]];
    }
    cout << nl[i]+1 << " ";
  }
}
