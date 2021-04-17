#include <bits/stdc++.h>

using namespace std;

//TLE but if print all even and then create an array of all the odds, it's OK

void josephus_problem(vector<int> & v, int i, int k){
  if(v.size() == 1){
    cout << v[0];
    return;
  }
  i = (i+k) % v.size();
  cout << v[i] << " ";
  v.erase(v.begin()+i);
  return josephus_problem(v, i, k);
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  iota(v.begin(),v.end(),1);
  josephus_problem(v,0,1);
}
