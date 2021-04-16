#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  cin >> n;
  ll a[n];
  ll s = 0;
  for(int i=0; i<n; ++i) cin >> a[i], s+=a[i];
  sort(a,a+n);
  cout << max(s, 2ll*a[n-1]);
}
