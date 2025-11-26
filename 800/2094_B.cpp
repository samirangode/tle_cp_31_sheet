#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, l, r;
    cin>>n>>m>>l>>r;
    int diff = n - m;
    int right = r - 0;
    int ans_l = 0, ans_r = 0;
    if(right>=diff){
        ans_l = l; ans_r = r - diff;
        cout<<ans_l<<" "<<ans_r<<endl;
        return;
    }
    else{
        ans_r = 0;
        diff = diff - right;
        ans_l = abs(l)  - diff;
        ans_l = -ans_l;
        cout<<ans_l<<" "<<ans_r<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

