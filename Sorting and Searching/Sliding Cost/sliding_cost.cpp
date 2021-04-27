#include <bits/stdc++.h>

using namespace std;

#define ll long long

int med = -1;
multiset<ll> bot, top;
ll sb, st;


void balance(){
  if(top.size() > bot.size()){
    auto it = top.begin();
    int x = *it;
    top.erase(it);
    st-=x;
    bot.insert(x);
    sb+=x;
  }
  if(top.size()+1 < bot.size()){
    auto it = --bot.end();
    int x = *it;
    bot.erase(it);
    sb-=x;
    top.insert(x);
    st+=x;
  }
  if(bot.size()!=0) med=*--bot.end();
}

void add(int x){
  if(bot.size()==0||x<=*--bot.end()){
    bot.insert(x);
    sb+=x;
  }else{
    top.insert(x);
    st+=x;
  }
  balance();
}

void rem(int x){
  auto it = bot.find(x);
  if(it!=bot.end()){
    bot.erase(it);
    sb-=x;
  }else{
    it = top.find(x);
    top.erase(it);
    st-=x;
  }
  balance();
}

int main(){
  int n, k;
  cin >> n >> k;
  ll a[n];
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<k-1; ++i) add(a[i]);
  for(int i=k-1; i<n; ++i){
    add(a[i]);
    cout << bot.size()*med-sb+st-top.size()*med << " ";
    rem(a[i-k+1]);
  }
}

