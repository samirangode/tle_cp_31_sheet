#include <bits/stdc++.h>
using namespace std;
#define int uint64_t

int xor_0_n(int n){
    int rem = n%4;
    if(rem==0){
        return n;
    }
    if(rem == 1){
        return 1;
    }
    if(rem==2){
        return n+1;
    }
    return 0;
}


int xor_range(int l, int r){
   return xor_0_n(r) ^ xor_0_n(l-1);
}

void solve(){
    int l, r, i, k;
    cin>>l>>r>>i>>k;
    int xor_rng = xor_range(l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
