#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin>>n;
    cin>>m;

    vector<long long> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    if(n>m){
        cout<<0<<endl;
        return 0;
    }

    long long ans = 1;
    for(int i = 0; i<(n-1); i++){
        for(int j = i+1; j<n; j++){
            ans = (ans%m * abs(a[i] - a[j])%m)%m;
        }
    }

    cout<<ans<<endl;


}
