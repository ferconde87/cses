#include <bits/stdc++.h>


using namespace std;

int movie_festival(vector<pair<int, int> > & v){
  sort(v.begin(),v.end());//sort first by end and then by start
  int ans = 0;
  int end = 0;
  for(auto p : v){
    if(end <= p.second){
      end = p.first;
      ans++;
    }
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for(int i = 0; i < n; ++i){
    int x, y;//x start time // y end time
    cin >> x >> y;
    v.push_back(make_pair(y,x));//this way the sorting will first sort by ending time.
  }

  cout << movie_festival(v) << endl;

  return 0;
}
