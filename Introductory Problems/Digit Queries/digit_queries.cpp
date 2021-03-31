#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define cn(x) cout << #x << " = " << x << endl;

char digit_queries(ll q, vector<ll> & v, vector<ll> & base){
  ll i = 0;
  while(q > v[i]) i++;
  q -= v[i-1];
  ll result = q / i;
  result += base[i];
  ll rem = q % i;
  return to_string(result)[rem]; 
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  vector<ll> v = {0,10};
  vector<ll> base = {0,0};
  ll x = 1;
  for(ll i = 2; i < 18; ++i){
    x *= 10;
    ll cur = i * 9 * x + v[i-1];
    v.push_back(cur);
    base.push_back(x);
  }

  for(int k = 1; k <= t; ++k){
    ll x;
    cin >> x;
    if(x <= 9) cout << x << endl;
    else cout << digit_queries(x, v, base) << endl;
  }

  return 0;
}
