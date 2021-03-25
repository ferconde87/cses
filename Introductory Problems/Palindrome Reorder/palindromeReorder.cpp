#include <bits/stdc++.h>

using namespace std;

bool allEven(vector<int> & count){
  for(int i = 0; i < count.size(); ++i){
    if(count[i] % 2 != 0) return false;
  }
  return true;
}

bool allEvenExceptOne(vector<int> & count){
  bool oneOddNumberFound = false;
  for(int i = 0; i < count.size(); ++i){
    if(count[i] % 2 == 0) continue;
    if(oneOddNumberFound) return false;
    oneOddNumberFound = true;
  }
  return true;
}


bool hasSolution(string & s, vector<int> & count){
  bool sizeEven = (s.size() % 2) == 0;
  if(sizeEven) return allEven(count);
  return allEvenExceptOne(count);
}

string palindromeReorder(string s){
  vector<int> count(26,0);
  for(char c : s){
    count[c - 'A']++;
  }

  if(!hasSolution(s, count)) return "NO SOLUTION";
  bool sizeEven = (s.size() % 2) == 0;
  char lastChar;
  string result;
  for(int i = 0; i < 26; ++i){
    if(count[i] == 0) continue;
    while(count[i] >= 2){
      result.push_back('A'+ i);
      count[i] -= 2;
    }
    if(count[i] == 1){
      lastChar = 'A' + i;
    }
  }

  if(!sizeEven){
    result.push_back(lastChar);
    result.append(result.rbegin()+1, result.rend());
  }else{
    result.append(result.rbegin(), result.rend());
  }
  
  return result;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  cout << palindromeReorder(s) << endl;
}
