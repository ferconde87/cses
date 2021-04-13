#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<int> s;
  int ans = 0;
  while(n--){
    int x;
    cin >> x;
    if(x==1){
      ans++;
    }else{
      auto it = s.find(x-1);
      if(it==s.end()) ans++;
    }
    s.insert(x); 
  }
  cout << ans << endl;
}
