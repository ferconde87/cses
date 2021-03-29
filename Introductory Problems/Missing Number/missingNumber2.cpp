#include <bits/stdc++.h>

using namespace std;    

#define ll long long

int main(){
    ll n, x, sum = 0;
    cin >> n;
    ll ans = n*(n+1)/2;
    for(int i = 1; i < n; ++i){
        ll x; 
        cin >> x;
        ans -= x;
    }
    cout << ans << endl;
    return 0;
}
