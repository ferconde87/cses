#include <bits/stdc++.h>

using namespace std;

//using n instead of v.size()

//TLE but if print all even and then create an array of all the odds, it's OK


int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  iota(v.begin(),v.end(),1);
  int i = 0;
  while(n){
    i = (i + 1) % n;
    cout << v[i] << " ";
    v.erase(v.begin()+i);
    --n;
  }
}
