#include <bits/stdc++.h>

using namespace std;    


int main(){

    string s;
    getline(cin, s);
    int n = s.size();
    if(n == 0) return 0;
    char ch = s[0];
    int counter = 1;
    int result = 1;
    for(int i = 1; i < n; ++i){
        char c = s[i];
        if(ch != c){
            ch = c;
            counter = 1;
        }else{
            counter++;
            if(counter > result){
                result = counter;
            }
        }
    }
    cout << result << endl;
            
    return 0;
}