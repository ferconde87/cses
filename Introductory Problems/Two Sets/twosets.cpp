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
    vector<bool> nums(n+1,false);
    int counter = 0;
    while(accum < half_sum){
        nums[cur] = true;
        counter++;
        cur--;
        accum+=cur;
    }
    accum-=cur;
    long long last_elem = 0; //last element of the first partiton 
    if(accum < half_sum){
        counter++;
        last_elem = half_sum - accum;
        nums[last_elem] = true;
    }

    cout << counter << endl;//size of the first partition
    cout << last_elem << " ";
    for(int i = cur+1; i <= n; ++i){
        cout << i << " ";
    }
    cout << endl;

    cout << n - counter << endl;//size of the other partition
    for(long long i = 1; i <= cur; ++i){
        if(i != last_elem){
            cout << i << " ";
        }
    }
    cout << endl;
                
    return 0;
}