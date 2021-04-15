#include <bits/stdc++.h>

using namespace std;

#define ar array

//assuming info of the guests are in order



int main(){
  int n;
  cin >> n;
  int lim = 1e9;
  set<ar<int,2> > s;
  s.insert({lim,lim});
  ar<int, 3> clients[n];
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    cin >> clients[i][1] >> clients[i][0];
    clients[i][2] = i;
  }

  sort(clients, clients+n);

  for(auto c : clients){
    auto it = s.lower_bound({c[1]});
    int room = 0;
    if(it-- != s.begin()){
      room = (*it)[1];
      s.erase(it);
    }else{
      room = s.size();
    }
    s.insert({c[0],room});
    v[c[2]] = room;
  }

  cout << s.size() - 1 << endl;
  for(int x : v) cout << x << " "; cout << endl; 
}
