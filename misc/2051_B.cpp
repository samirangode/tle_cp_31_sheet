#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, a, b, c;
    cin>>n;
    cin>>a;
    cin>>b;
    cin>>c;
    long long sum = a+b+c;
    long long div = n / sum;
    long long ans = div*3;
    long long rest = n%sum;
    if(rest>0){
        rest-=a;
        ans+=1;
    }
    if(rest>0){
        rest-=b;
        ans+=1;
    }
    if(rest>0){
        rest-=c;
        ans+=1;
    }
    if(rest>0){
        cout<<"err: check cond"<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
