#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 0; i<(n-1); i++){
        int temp;
        cin>>temp;
        sum+=temp;
    }
    cout<<-1*sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
