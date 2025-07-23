#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow_rec(ll a, ll b){
    if(b==0) return 1ll;
    ll ans = 1;
    if(b&1){
        ans= ans*a;
    }
    ll half_pow = binpow_rec(a,b/2);
    ans = ans*half_pow*half_pow;
    return ans;
}


ll binpow(ll a, ll b){
    ll ans=1;

    while(b>0){
        if(b&1){
            ans = ans*a;
        }
        a = a * a;
        b = b>>1;
    }
    return ans;
    
}

int main(){
    ll n;
    cin>>n;

    ll ans = 2 * 4 * 3 * binpow_rec(4ll,(ll)(n-3));
    if(n>3){
        ans+= (n-3)*4*3*3*binpow_rec(4,n-4);
    }

    cout<<ans<<endl;

}
