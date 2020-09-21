#include <bits/stdc++.h>

using namespace std; 

//if we don't have to return the amount of elements of each partition, we can calculate in-line using only constant variables

int main(){

    long long n;
    cin >> n;
    long long sum = n*(n+1) / 2; //sum of all elements
    long long half_sum = 0;
    if(sum % 2 == 1){
        cout << "NO\n";
        return 0;
    }else{
        half_sum = sum / 2;
    }
    cout << "YES\n";
    long long cur = n;
    long long accum = cur;
    while(accum < half_sum){
        cout << cur << " ";
        cur--;
        accum+=cur;
    }
    accum-=cur;
    long long last_elem = 0; // last element of the first partiton 
    if(accum < half_sum){
        last_elem = half_sum - accum;
        cout << last_elem << "\n";
    }else{
        cout << "\n";
    }
    for(long long i = 1; i <= cur; ++i){
        if(i != last_elem){
            cout << i << " ";
        }
    }
                
    return 0;
}