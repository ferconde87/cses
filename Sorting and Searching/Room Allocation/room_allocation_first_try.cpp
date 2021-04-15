#include <bits/stdc++.h>

using namespace std;

//assuming info of the guests are in order

int main(){
  int n;
  cin >> n;
  int lim = 1e9;
  set<pair<int,int> > s;
  s.insert(make_pair(lim,lim));
  vector<int> v;
  while(n--){
    int a, b;
    cin >> a >> b;
    auto it = s.begin();
    int room = 0;
    if(it->first < a){
      room = it->second;
      s.erase(it);
    }else{
      room = s.size();
    }
    s.insert(make_pair(b,room));
    v.push_back(room);
  }
  cout << s.size() - 1 << endl;
  for(int x : v) cout << x << " "; cout << endl; 
}
