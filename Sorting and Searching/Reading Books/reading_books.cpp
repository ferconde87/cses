#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  cin >> n;
  ll a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a,a+n);
  int i = 0;
  int j = n-1;
  ll l = 0;
  ll r = 0;
  while(i < n && j >= 0){
    while(i < n && j >= 0 && r+a[j] > l+a[i] && i != j){
      l+=a[i]; i++;
    }
    while(i < n && j >= 0 && r+a[j] < l+a[i] && i != j){
      r+=a[j]; j--;
    }
    while(i < n && j >= 0 && i != j){
      if(a[j] < a[i]){
        r+=a[j]; j--;
      }else{
        l+=a[i]; i++;
      }
    }
    if(i < n && j >= 0 && i == j){
      ll diff = abs(l-r);
      if(l < r){
        r += min(a[i], a[i]-diff);
        l+=a[i];
        i++;
      }else{
        l += min(a[i], a[i]-diff);
        r+=a[i];
        j--;
      }
    }
  }
  while(i < n){
    l+= a[i]; ++i;
  }
  while(j >= 0){
    r+= a[j]; --j;
  }
  cout << max(l,r) << endl;
}
