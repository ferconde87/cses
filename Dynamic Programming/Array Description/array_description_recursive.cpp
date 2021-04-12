#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
int ans = 0;
 
#define cn(x) cout << #x << " = " << x << endl;
 
void rec(vector<int> & v, int i, int last, int n, int m){
 
  if(i == n){
    ans++;
    ans = ans % mod;
    return;
  } 
  if(i==0 && v[i]==0){
    for(int k = 1; k <= m; ++k){
      rec(v,i+1,k,n,m);
    }
    return;
  }
  if(i==0){
    rec(v,i+1,v[i],n,m);
    return;
  }
  if(v[i]==0){
    for(int k = -1; k <=1; ++k){
      if(last+k==0||last+k>m)continue;
      rec(v,i+1,last+k,n,m);
    }
    return; 
  }
  if(v[i]!=last && v[i]!=last+1 && v[i]!=last-1){
    return;
  }
  rec(v,i+1,v[i],n,m);
}
 
int main(){
 
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for(int&x:v)cin>>x;
  rec(v,0,0,n,m);
  cout << ans << endl;
}
