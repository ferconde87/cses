#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n, target;
  cin >> n >> target;
  unordered_map<ll, int> m;
  m.reserve(1<<18);
  ll sum = 0;
  int ans = 0;
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
