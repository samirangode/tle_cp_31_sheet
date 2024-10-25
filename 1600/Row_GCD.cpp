#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int n, m;

    cin>>n>>m;

    vector<ll> a(n);
    vector<ll> c(n);
    vector<ll> b(m);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    
    ll gcd_val = 0;

    for(int i =1; i<n; i++){
        c[i] = a[i]-a[0];
        gcd_val = __gcd(c[i], gcd_val);
    }
    for(int i = 0; i<m; i++){
        // for each b
        c[0] = a[0] + b[i];

        ll new_gcd = __gcd(c[0], gcd_val);

        cout<<abs(new_gcd)<<" ";

    }
    cout<<"\n";

    return 0;
}
