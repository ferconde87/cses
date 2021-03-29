#include <bits/stdc++.h>

using namespace std;    

int main(){

    string s;
    getline(cin, s);
    int n = s.size();
    char last = 'A';
    int counter = 0;
    int result = 0;
    for(char c : s){
        if(c == last){
            counter++;
            if(counter > result)
                result = counter;
        }else{
            last = c;
            counter = 1;
        }
    }
    cout << result << endl;
            
    return 0;
}
