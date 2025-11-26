#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int xor_val= 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        xor_val=a[i]^xor_val;
    }
    if(n&1){
        cout<<xor_val<<endl;
    }
    else{
        if(xor_val){
            cout<<-1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }


   
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
