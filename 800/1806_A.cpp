#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    long long a, b, c, d;
    cin>>a>>b>>c>>d;
    
    if(d<b){
        cout<<-1<<endl;
        return;
    }
    long long move = 0;
    move+= (d-b);
    a = a + (d-b);
    b = d;
    if(a<c){
        cout<<-1<<endl;
        return;
    }
    move+= (a-c);
    cout<<move<<endl;
   
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
