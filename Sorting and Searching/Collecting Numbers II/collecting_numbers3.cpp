#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void print(vector<int> & v){
  for(int x : v) cout << x << " "; cout << endl;
}

void fa(vector<int> & index, int prev, int post, int i, int j){
  if(index[prev] < i && index[prev] > j) ans++;
  if(index[prev] > i && index[prev] < j) ans--;
  if(index[post] > i && index[post] < j) ans++;
  if(index[post] < i && index[post] > j) ans--;
  // if(index[prev] == i) ans++;
  if(index[prev] == j) ans--;
  if(index[post] == j) ans++;
  // if(index[post] == i) ans--;
}

void fb(vector<int> & index, int prev, int post, int i, int j){
  if(index[prev] < j && index[prev] > i) ans++;
  if(index[prev] > j && index[prev] < i) ans--;
  if(index[post] > j && index[post] < i) ans++;
  if(index[post] < j && index[post] > i) ans--;
}



int main(){
  int n, m;
  cin >> n >> m;
  unordered_set<int> s;
  vector<int> index(n+1);
  vector<int> v(n+1);
  index[0] = 0;
  v[0] = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    index[x] = i;
    v[i] = x;
    if(x==1){
      ans++;
    }else{
      auto it = s.find(x-1);
      if(it==s.end()) ans++;
    }
    s.insert(x); 
  }

  while(m--){
    int a, b;
    cin >> a >> b;
    fa(index,v[a]-1,v[a]+1,a,b);
    fb(index,v[b]-1,v[b]+1,a,b);
    swap(v[a],v[b]);
    swap(index[v[a]],index[v[b]]);
    cout << ans << endl;
  }

  return 0;
}
