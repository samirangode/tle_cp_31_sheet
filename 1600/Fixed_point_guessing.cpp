#include <bits/stdc++.h>

using namespace std;



void solve(){
    int n;
    cin>>n;
    int l = 1, r = n;
    while(l<r){
        int mid = l + (r-l)/2;
        cout<<"?"<<" "<<l<<" "<<mid<<endl;
        cout.flush();
        int x, count = 0;
        for(int i = 0; i<(mid-l+1); i++){
            cin>>x;
            assert(x!=(-1));
            if(x>=l && x<=mid) count++;
        }
        if(count&1){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<"! "<<l<<endl;
    cout.flush();
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

