#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bs(vector<ll>& a, vector<ll>& b, int i){
    int lo = 0;
    int hi = b.size()-1;
    int ans = lo;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if((b[mid] - a[i]) > a[i+1]){
            hi = mid - 1;
        }
        else{
            ans = mid;
            lo = mid + 1;
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    // sort b
    sort(b.begin(), b.end());
    bool ans = true;
    for(int i = n-1; i>=0; i--){
        // maximize for each element
        if(i==(n-1)){
            a[i] = max(a[i], b[m-1]-a[i]);
        }
        else if(i<(n-1)){
            // check greatest j for which b[j] - a[i] <= a[i+1]
            // check if a[i] <= a[i+1] check if b[j] - a[i] <= a[i+1]
            // if no j matches and if a[i]> a[i+1] false
            // if one of the condition holds take that
            // if both hold take the max
            int j = bs(a,b,i);
            ll bs_out = b[j] - a[i];
            if(bs_out<=a[i+1] && a[i]<=a[i+1]){
                a[i] = max(a[i], bs_out);
            }
            else{
                if(a[i]>a[i+1] && bs_out>a[i+1]){
                    ans =false;
                    break;
                }
                else if(bs_out<=a[i+1]){
                    a[i] = bs_out;
                }
            }
            // if(a[i]>a[i+1]){
            //     a[i] = b[0] - a[i];
            // }
            // else{
            //     ll max_possible = max(a[i], b[0]-a[i]);
            //     if(max_possible<=a[i+1]){
            //         a[i] = max_possible;
            //     }
            // }
            // if(a[i]>a[i+1]){
            //     ans = false;
            //     break;
            // }
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
