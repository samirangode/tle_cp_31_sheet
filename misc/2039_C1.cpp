#include <bits/stdc++.h>

using namespace std;

void run(){
    long long x, m;
    cin>>x>>m;
    long long lim = min(m,2*x);
    long long ans=0;
    for(long long y = 1; y<=lim; y++){
        long long num = x^y;
        if((num!=0) && ((x%num==0) || y%num==0)){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        run();
    }
}
