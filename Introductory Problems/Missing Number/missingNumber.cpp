#include <bits/stdc++.h>

using namespace std;    


int main(){

    int n;
    cin >> n;

    vector<bool> v(n+1, false);
    for(int i = 1; i < n; ++i){
        int x; 
        cin >> x;
        v[x] = true;
    }

    for(int i = 1; i <= n; ++i){
        if(!v[i]){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}