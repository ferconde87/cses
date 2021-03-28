#include <bits/stdc++.h>
using namespace std;
 
 int result = 0;
 vector<pair<int, int> > v;

void towerOfHanoi(int n, int from, int to, int aux, int moves) {
  if (n == 1){
    v.push_back(make_pair(from, to));
    return;
  }
  result++;
  towerOfHanoi(n - 1, from, aux, to, moves+1);
  v.push_back(make_pair(from, to));
  result++;
  towerOfHanoi(n - 1, aux, to, from, moves+1);
}
 
int main() {
  int n;
  cin >> n,
  towerOfHanoi(n, 1, 3, 2, 0); 
  cout << result+1 << endl;
  for(auto p : v){
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
