#include <bits/stdc++.h>

using namespace std;

//still need to consider abs(v[a]-v[b])=1
//but i'm considering other approach keeping track of the numbers that start a new 'swipe'
//and checking if after swap, they still start a new swipe. But also I need to check if prev and post create swipes or not

int ans = 0;
void print(vector<int> & v){
  for(int x : v) cout << x << " "; cout << endl;
}

void f(vector<int> & index, int prev, int post, int i, int j){
  if(index[prev] <= i && index[prev] >= j) ans++;
  if(index[prev] >= i && index[prev] <= j) ans--;
  if(index[post] >= i && index[post] <= j) ans++;
  if(index[post] <= i && index[post] >= j) ans--;
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
    f(index,v[a]-1,v[a]+1,a,b);
    f(index,v[b]-1,v[b]+1,b,a);
    swap(index[v[a]],index[v[b]]);
    swap(v[a],v[b]);
    cout << ans << endl;
  }

  return 0;
}
