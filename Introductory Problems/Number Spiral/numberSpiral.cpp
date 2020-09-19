#include <bits/stdc++.h>

using namespace std;    


int main(){

    int t;
    long long r, c;
    cin >> t;

    for(int k = 0; k < t; ++k){
        cin >> r >> c;

        long long z = max(c,r);
        long long diag = z*z - (z-1);

        if(c < z){
            if(z % 2 == 1){
                cout << diag - (z - c)  << endl;
            }else{
                cout << diag + (z - c)  << endl;
            }
        }else{
            if(z % 2 == 1){
                cout << diag + (z - r)  << endl;
            }else{
                cout << diag - (z - r)  << endl;
            }
        }
    }
    
    return 0;
}       