#include <bits/stdc++.h>


using namespace std;

//Using array<int, 2> instead of pair

int movie_festival(vector<array<int, 2> > & v){
  sort(v.begin(),v.end());//sort first by end and then by start
  int ans = 0;
  int end = 0;
  for(auto p : v){
    if(end <= p[1]){
      end = p[0];
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
  vector<array<int, 2> > v(n);
  for(int i = 0; i < n; ++i){
    int x, y;//x start time // y end time
    cin >> v[i][1] >> v[i][0];
  }

  cout << movie_festival(v) << endl;

  return 0;
}
