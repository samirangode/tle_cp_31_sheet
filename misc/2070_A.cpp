#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    long long ans=0;
    long long k = n/15;
    if(k==0){
        for(int i = 15*k; i<=min(15*k+2,n); i++){
            ans+=1;
        }
        cout<<ans<<endl;
        return;
    }
    ans+=3;
    if((k-1)>0){
        ans+= (k-1)*3; 
    }
    for(int i = 15*k; i<=min(15*k+2,n); i++){
        ans+=1;
    }
    cout<<ans<<endl;
    return; 
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
