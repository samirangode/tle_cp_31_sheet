#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin>>a>>b;

    long long x=0;
    if((b%a)==0){
        int p = b/a;
        x = b*p;
    }
    else{
        int p = a/__gcd(a,b);
        x = b*p;
    }
    cout<<x<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
