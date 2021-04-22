#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n;
  cin >> n;
  map<ll, int> m;
  ll sum = 0;
  ll ans = 0;
  ll cur;
  m[0]=1;
  for(int i=0; i<n; ++i){
    cin >> cur;
    sum+=cur;
    sum = sum % n;
    if(sum < 0) sum += n;
    ans+=m[sum];
    m[sum]++;
  }
  cout << ans;
}
