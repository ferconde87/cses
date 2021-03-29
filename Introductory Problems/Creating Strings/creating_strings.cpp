#include <bits/stdc++.h>

using namespace std;

string create_string(string s, vector<int> & indices){
  string result;
  for(int x : indices){
    result.push_back(s[x]);
  }
  return result;
}

set<string> creating_strings(string s){
  int n = s.size();
  vector<int> indices(n);
  for(int i = 0; i < n; ++i) indices[i] = i;
  set<string> result;
  do {
    string cur = create_string(s, indices);
    if(result.find(cur) == result.end()){
      result.insert(cur);
    }
  } while(next_permutation(indices.begin(), indices.end()));
  return result;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  sort(s.begin(), s.end()); 
  set<string> result = creating_strings(s);
  cout << result.size() << endl;
  for(string s : result){
    cout << s << endl;
  }

  return 0;
}
