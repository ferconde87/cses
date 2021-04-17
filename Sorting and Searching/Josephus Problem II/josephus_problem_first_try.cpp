#include <bits/stdc++.h>

using namespace std;

//TLE code simple

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  int i = 0;
  while(n){
    i = (i + k) % n;
    cout << v[i] << " ";
    v.erase(v.begin()+i);
    --n;
  }
}
