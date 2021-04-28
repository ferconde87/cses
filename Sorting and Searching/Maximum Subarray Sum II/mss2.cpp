#include <bits/stdc++.h>

using namespace std;

#define ll long long

//mss2.cpp:searching the max value in the set. So the answer is maxValue - sum[i-b]
//mss.cpp is simpler. Search for the minValue so the answer is sum[i]-minValue


int main(){
  int n;
  ll a, b;
  cin >> n >> a >> b;
  ll sum[n+1];
  for(int i=1; i<=n; ++i){
    cin >> sum[i];
    sum[i]+=sum[i-1];
  } 
  multiset<ll> s;
  ll ans=LONG_LONG_MIN;

  for(int i=a; i<b; ++i) s.insert(sum[i]);

  for(int i=b; i<=n; ++i){
    s.insert(sum[i]);
    ans=max(*--s.end()-sum[i-b],ans);
    auto it = s.find(sum[i-(b-a)]);
    s.erase(it);
  }
  for(int i=b-1; i >= a; --i){
    if(s.size()){
      auto it = s.find(sum[n-(i-a+1)]);
      if(it != s.end()) s.erase(it);
    }
    ans=max(*--s.end()-sum[n-i],ans);
  }
  cout << ans << endl;
}
