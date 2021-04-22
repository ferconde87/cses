#include <bits/stdc++.h>

using namespace std;

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
    if(a[j] > target){
      ++j;
      continue;
    }
    if(sum+a[j] < target){
      sum+=a[j];
      ++j;
    }else if(sum+a[j] < target){
      sum-=a[i];
      ++i;
    }else{
      ans++;
      j++;
    }
  }
}
