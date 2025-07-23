#include <bits/stdc++.h>
using namespace std;

int cal( int i, int j){
    int min_i = min(abs(i-5), abs(i-6));
    int min_j = min(abs(j-5), abs(j-6));
    return 5 - min(min_i, min_j);
}

void solve(){
    vector<string> a(10);
    for(int i = 0; i<10; i++){
        cin>>a[i];
    }
    int sum = 0;
    for(int i = 0; i< 10; i++){
        for(int j = 0; j<10; j++){
            if(a[i][j]=='X'){
                int val = cal(i+1,j+1);
                sum+=val;
            }
        }
    }
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
