#include <bits/stdc++.h>

using namespace std;


void solve(){
    string s;
    cin>>s;
    if(s.length()==2){
        cout<<"i"<<endl;
        return;
    }
    cout<<s.substr(0,s.length()-2)<<"i"<<endl;
    return;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}