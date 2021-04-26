#include <bits/stdc++.h>

using namespace std;

#define ar array

multiset<int> top, bot;
int med = -1;

void fix(){
  int m = 1 + bot.size() + top.size();
  if(bot.size() < (m-1)/2){
    bot.insert(med);
    auto it = top.begin();
    med = *it;
    top.erase(it);
  }
  if(bot.size() > (m-1)/2){
    top.insert(med);
    auto it = --bot.end();
    med = *it;
    bot.erase(it);
  }
}

void add(int x){
  if(med == -1) {
    med = x;
    return;
  }
  if(x < med){
    bot.insert(x);
  }else{
    top.insert(x);
  }
  fix();
}

void rem(int x){
  if(x == med) {
    auto it = top.begin();
    med = *it;
    top.erase(it);
  } else if(x < med) {
    auto it = bot.find(x);
    bot.erase(it);
  } else {
    auto it = top.find(x);
    top.erase(it);
  }
  fix();
}

int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];

  if(k==1){
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
  }

  for(int i = 0; i < k-1; ++i) add(a[i]);
  
  for(int i = k-1; i < n; ++i){
    add(a[i]);
    cout << med << " ";
    rem(a[i-k+1]);
  }
  return 0;
}
 