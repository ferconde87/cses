#include <bits/stdc++.h>

using namespace std;    


int main(){

    long long t;
    cin >> t;
    long long a, b;
    for(int i = 0; i < t; ++i){
        cin >> a >> b;
        if(2*a < b || 2*b < a){
            cout << "NO\n";
            continue;
        }
        long long rem = (a + b) % 3;
        if(rem == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    return 0;

}
