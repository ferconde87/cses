#include <bits/stdc++.h>

using namespace std;

//greedy...missing cases

int main(){
  int n, x;
  cin >> n >> x;
  int a[n];
  for(int i=0; i<n; ++i) cin >> a[i];
  int i = 0;
  int j = 0;
  int sum = 0;
  int ans = 0;
  while(j < n){
    if(sum+a[j] < x){
      sum+=a[j];
      ++j;
    }else if(sum+a[j] > x){
      sum-=a[i];
      ++i;
    }else{
      ans++;
      j++;
    }
  }
  cout << ans;
}
