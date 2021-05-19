#include <bits/stdc++.h>

using namespace std;

//WA greedy

int main(){
  int a, b;
  cin >> a >> b;
  int ans=0;
  while(a!=1||b!=1){
    int c = min(a,b);
    if(a > c)
      a-=c;
    else if(b > c)
      b-=c;
    else
      break;
    ans++;
  }
  cout << ans;
}
