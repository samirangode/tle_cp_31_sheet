#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k, x;
    cin>>n>>k>>x;

    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i = 1; i<=n; i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    else if(k==1 or (k==2 and n%2==1)){
        cout<<"NO"<<endl; return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        if(n%2) cout<<3<<" ";
        else cout<<2<<" ";
        for(int i = 1; i<=((n/2)-1); i++){
            cout<<"2"<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
