#include <bits/stdc++.h>

using namespace std;

struct tower{
  int sum = 0;
  stack<int> s;
};

int pos(int l, int m, int r){
  return 100*l + 10*m + r;
}

int result = INT_MAX;

void tower_of_hanoi(tower left, tower mid, tower right, unordered_set<int> memo, int moves, int obj){

  int p = pos(left.sum,mid.sum,right.sum);

  // cout << left.sum << " " << mid.sum << " " << right.sum << endl; 

  if(p == obj){
    if(moves < result){
      result = moves;
      cout << "partial solution = " << result << endl;
    }
    return;
  }

  int l = (left.s.empty()) ? 0 : left.s.top();
  int m = (mid.s.empty()) ? 0 : mid.s.top();
  int r = (right.s.empty()) ? 0 : right.s.top();

  if((l > 0) && (l < m || m == 0)){
    int newPos = pos(left.sum-l,mid.sum+l,right.sum);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      left.s.pop();
      left.sum -= l;
      mid.s.push(l);
      mid.sum += l;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      left.s.push(l);
      left.sum += l;
      mid.s.pop();
      mid.sum -= l;
    }
  }

  if((l > 0) && (l < r || r == 0)){
    int newPos = pos(left.sum-l,mid.sum,right.sum+l);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      left.s.pop();
      left.sum -= l;
      right.s.push(l);
      right.sum += l;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      left.s.push(l);
      left.sum += l;
      right.s.pop();
      right.sum -= l;
    }
  }

  if((m > 0) && (m < l || l == 0)){
    int newPos = pos(left.sum+m,mid.sum-m,right.sum);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      mid.s.pop();
      mid.sum -= m;
      left.s.push(m);
      left.sum += m;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      mid.s.push(m);
      mid.sum += m;
      left.s.pop();
      left.sum -= m;
    }
  }

  if((m > 0) && (m < r || r == 0)){
    int newPos = pos(left.sum,mid.sum-m,right.sum+m);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      mid.s.pop();
      mid.sum -= m;
      right.s.push(m);
      right.sum += m;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      mid.s.push(m);
      mid.sum += m;
      right.s.pop();
      right.sum -= m;
    }
  }

  if((r > 0) && (r < l || l == 0)){
    int newPos = pos(left.sum+r,mid.sum,right.sum-r);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      right.s.pop();
      right.sum -= r;
      left.s.push(r);
      left.sum += r;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      right.s.push(r);
      right.sum += r;
      left.s.pop();
      left.sum -= r;
    }
  }

  if((r > 0) && (r < m || m == 0)){
    int newPos = pos(left.sum,mid.sum+r,right.sum-r);
    if(memo.find(newPos) == memo.end()){
      memo.insert(newPos);
      right.s.pop();
      right.sum -= r;
      mid.s.push(r);
      mid.sum += r;
      tower_of_hanoy(left, mid, right, memo, moves+1, obj);
      right.s.push(r);
      right.sum += r;
      mid.s.pop();
      mid.sum -= r;
    }
  }

}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<int> memo;
  int n;
  cin >> n;
  memo.insert(pos(n,0,0));
  tower left;
  tower right;
  tower mid;
  stack<int> s;
  for(int k = n; k >= 1; --k) s.push(k);
  left.s = s;
  left.sum = n*(n+1)/2;
  tower_of_hanoi(left, right, mid, memo, 0, left.sum);
  cout << result << endl;
  return 0;
}
