#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, target;
  cin >> n >> target;
  vector<int> prices(n+1,0);
  for(int i = 1; i <= n; ++i) cin >> prices[i];
  vector<int> pages(n+1,0);
  for(int i = 1; i <= n; ++i) cin >> pages[i];
  vector<vector<int> > best(target+1, vector<int>(n+1,0));

  for(int i = 1; i <= n; ++i){
    for(int x = 1; x <= target; ++x){
      best[x][i] = best[x][i-1];
      if(prices[i] <= x) 
        best[x][i] = max(best[x][i], best[x-prices[i]][i-1]+pages[i]);
    }
  }

  cout << best[target][n] << endl;
}
