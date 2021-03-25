#include <bits/stdc++.h>

using namespace std;

void grayScale(int n){
  vector<string> result(1,"");
  for(int i = 1; i <= n; ++i){
    int limit = pow(2,i);
    int half = limit/2;
    vector<string> temp = result;
    result.insert(result.end(), temp.rbegin(), temp.rend());
    for(int j = 0; j < half; ++j){
      result[j].insert(0, "0");
    }
    for(int j = half; j < limit; ++j){
      result[j].insert(0, "1");
    }
  }
  for(string s : result){
    cout << s << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  grayScale(n);
}
