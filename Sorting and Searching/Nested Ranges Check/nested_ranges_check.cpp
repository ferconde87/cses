#include <bits/stdc++.h>

using namespace std;

#define ar array

int main(){
  int n;
  cin >> n;
  ar<int,3> a[n];
  for(int i = 0; i < n; ++i){
    cin >> a[i][1] >> a[i][0];
    a[i][2] = i;
  }
  sort(a,a+n);

  set<ar<int,3> > s;
  vector<int> ans1(n,0);
  vector<int> ans2(n,0);
  for(auto cur : a){
    int l = cur[1];
    int r = cur[0];
    int i = cur[2];
    // cout << i << endl;
    auto it = s.lower_bound({l});
    if(it == s.end() && it == s.begin()) {
      s.insert({l,r,i});
      continue;
    }
    if(it == s.begin() || l <= (*s.begin())[0]){
      ans1[i] = 1;
      for(auto it2 = it; it2 != s.end(); ++it2)
        ans2[(*it2)[2]] = 1;
      s.erase(it,s.end());
    }else{
      // --it;
      if(l > (*it)[0]) --it;
      if(l > (*it)[0]){
        // cout << "(" << l << ", " << r << ")\n";
        // cout << "(*it)[0] = " << (*it)[0] << endl;
        // cout << "(*it)[1] = " << (*it)[1] << endl;
        if(r == (*it)[1]){
          ans1[(*it)[2]] = 1;
          ans2[i] = 1;
        }
      }else{
        if(l == (*it)[0]){
          if(r > (*it)[1]){
            ans1[i] = 1;
            ans2[(*it)[2]] = 1;
          }
        }
      }
    }
    // cout << "> " << l << " " << r << " " << i << endl;
    s.insert({l,r,i});

    // for(auto c : s){
    //   cout << "(" << c[0] << " " << c[1] << " " << c[2] << ")" << endl;
    // }
  }
  for(int x : ans1) cout << x << " "; cout << endl;
  for(int x : ans2) cout << x << " "; cout << endl;    
}
