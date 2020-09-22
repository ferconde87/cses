#include <bits/stdc++.h>

using namespace std;    

int main(){

    long long n;
    cin >> n;
    long long result = 1;
    for(int i = 1; i <= n; ++i){
        result = result*2 % 1000000007LL;
    }
    cout << result << endl;
    
    return 0;
}