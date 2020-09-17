#include <bits/stdc++.h>

using namespace std;    


int main(){

    long long n;
    cin >> n;

    vector<long long> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    long long result = 0;
    for(int i = 0; i < n - 1; ++i){
        if(v[i] > v[i+1]){
            result += (v[i] - v[i+1]);
            v[i+1] = v[i];
        }
    }

    cout << result << endl;
    
    return 0;
}