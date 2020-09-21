#include <bits/stdc++.h>

using namespace std; 

//this is just a proof for the case n = 100000 :) just for fun

int main(){

    long long a = 70712;
    long long sum = 100001LL*100000LL/2;
    long long half_sum = sum / 2;

    long long accum = 0;
    for(long long i = a; i <= 100000; ++i){
        accum += i;
    }

    long long last_elem = half_sum - accum;//should be a positive number and lest than 70711

    accum += last_elem;

    if(accum == half_sum){
        cout << "OK\n";
    }else{
        cout << "NOT OK\n";
    }

    long long accum_second_half = 0;
    for(long long i = 1; i < a; ++i){
        if(last_elem != i) 
            accum_second_half += i;
    }

    if(accum_second_half == accum){
        cout << "COOL\n";
    }else{
        cout << "NOT COOL\n";
    }

    return 0;
}