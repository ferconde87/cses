#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  sort(s.begin(), s.end()); 
  vector<string> ans;
  do {
    ans.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  cout << ans.size() << endl;
  for(string s : ans){
    cout << s << endl;
  }

  return 0;
}
