#include <bits/stdc++.h>

using namespace std;

//memory: O(target*N)

int main(){
  int n, target;
  cin >> n >> target;
  vector<int> prices(n+1,0);
  for(int i = 1; i <= n; ++i) cin >> prices[i];
  vector<int> pages(n+1,0);
  for(int i = 1; i <= n; ++i) cin >> pages[i];
  vector<vector<int> > best(n+1, vector<int>(target+1,0));

  for(int i = 1; i <= n; ++i){
    best[i] = best[i-1];
    for(int x = prices[i]; x <= target; ++x){
      best[i][x] = max(best[i][x], best[i-1][x-prices[i]]+pages[i]);
    }
  }

  cout << best[n][target] << endl;
}
