#include <bits/stdc++.h>

using namespace std;    


int main(){

    long long n;
    cin >> n;
    long long result = 0;

    vector<long long> powerOf5;
    for(long long current = 5; current <= 1000000000; current *= 5){
        powerOf5.push_back(current);
    }

    for(unsigned int i = 0; i < powerOf5.size() && n >= powerOf5[i]; ++i){
        result += n / powerOf5[i];
    }

    cout << result << endl;
    
    return 0;
}