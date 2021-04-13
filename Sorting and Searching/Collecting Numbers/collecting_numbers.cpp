#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> s;
  int ans = 0;
  while(n--){
    int x;
    cin >> x;
    if(x==1){ 
      ans++;
    }else{
      auto it = s.lower_bound(x-1);
      if(*it!=x-1) ans++;
    }
    s.insert(x); 
  }
  cout << ans << endl;
}
