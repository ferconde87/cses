#include <bits/stdc++.h>

using namespace std;

//memory: O(target)

#define ar array

int main(){
  int n, target;
  cin >> n >> target;
  ar<int,2> p[n+1];
  p[0] = {0,0};
  for(int i = 1; i <= n; ++i) cin >> p[i][0];
  for(int i = 1; i <= n; ++i) cin >> p[i][1];
  vector<int> best(target+1, 0);
  vector<int> last(target+1, 0);

  for(int i = 1; i <= n; ++i){
    for(int x = p[i][0]; x <= target ; ++x){
      best[x] = max(best[x], last[x-p[i][0]]+p[i][1]);
    }
    last = best;
  }
  
  cout << best[target] << endl;
}
