#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    string x, s;
    cin>>x;
    cin>>s;

    // for each operation;
    for(int o = 0; o<=5; o++){
        //create the string
        string new_x = x;
        for(int c = 1; c<=o; c++){
            new_x+=new_x;
        }
        // check
        // int new_n = new_x.size();
        size_t ind = new_x.find(s);
        if(ind!=string::npos){
            cout<<o<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
