#include <bits/stdc++.h>

using namespace std;

int med = -1;
multiset<int> bot, top;

void balance(){
  if(top.size() > bot.size()){
    auto it = top.begin();
    int x = *it;
    top.erase(it);
    bot.insert(x);
  }
  if(top.size()+1 < bot.size()){
    auto it = --bot.end();
    int x = *it;
    bot.erase(it);
    top.insert(x);
  }
  if(bot.size()!=0) med=*--bot.end();
}

void add(int x){
  if(bot.size()==0||x<=*--bot.end()){
    bot.insert(x);
  }else{
    top.insert(x);
  }
  balance();
}

void rem(int x){
  auto it = bot.find(x);
  if(it!=bot.end()){
    bot.erase(it);
  }else{
    it = top.find(x);
    top.erase(it);
  }
  balance();
}

int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<k-1; ++i) add(a[i]);
  for(int i=k-1; i<n; ++i){
    add(a[i]);
    cout << med << " ";
    rem(a[i-k+1]);
  }
}

