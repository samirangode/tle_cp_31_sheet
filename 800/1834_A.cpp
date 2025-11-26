#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int num_1 = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==1) num_1++;
    }
    int ans = 0;
    if(n&1){
        int required = n/2 + 1;
        if(num_1 < required){
            ans += (required-num_1);
            if((n-required)&1)  ans+=1;
        }
        else{
            if((n-num_1)&1){
                ans+=1;
            }
        }
    }
    else{
        int required = n/2;
        if(num_1<required){
            ans+= (required-num_1);
            if(required&1) ans+=1;
        }
        else{
            if((n-num_1)&1){
                ans+=1;
            }
        }
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
