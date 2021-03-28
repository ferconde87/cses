#include <bits/stdc++.h>
using namespace std;
 
 int result = 0;
 vector<pair<int, int> > v;

void towerOfHanoi(int n, int from, int to, int aux) {
  if (n == 1){
    result++;
    v.push_back(make_pair(from, to));
    return;
  }
  
  towerOfHanoi(n - 1, from, aux, to);
  
  v.push_back(make_pair(from, to));
  result++;
  
  towerOfHanoi(n - 1, aux, to, from);
}
 
int main() {
  int n;
  cin >> n,
  towerOfHanoi(n, 1, 3, 2); 
  cout << result << endl;
  for(auto p : v){
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
