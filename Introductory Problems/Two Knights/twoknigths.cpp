#include <bits/stdc++.h>

using namespace std;

void twoknights(long long k ){
  for(long long i = 1; i <= k; ++i){
    long long totalPositions = i*i*((i*i)-1)/2;
    long long attackedPositions = 4*(i-1)*(i-2);
    cout << totalPositions - attackedPositions << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long k;
  cin >> k;
  twoknights(k);
}
