#include <bits/stdc++.h>

using namespace std;

#define ll long long

//note: with unordered_map and even using m.reserve(1<<18) it gets LTE

int main(){
  int n, target;
  cin >> n >> target;
  map<ll, int> m;
  ll sum = 0;
  ll ans = 0;
  ll cur;
  m[0]=1;
  for(int i=0; i<n; ++i){
    cin >> cur;
    sum+=cur;
    ans+=m[sum-target];
    m[sum]++;
  }
  cout << ans;
}
