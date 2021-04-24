#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i=0; i<n; ++i)cin>>a[i];
  ll lb=*max_element(a,a+n);
  ll rb=1e18;
  while(lb<rb){
    ll mb=(lb+rb)/2;
    int c=0;
    ll ls=0;
    for(int i=0; i<n; ++i){
      if(ls+a[i]>mb){
        ++c;
        ls=0;
      }
      ls+=a[i];
    }
    ++c;
    if(c>k)
      lb=mb+1;
    else
      rb=mb;
  }
  cout << lb;
}
