#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];

    unordered_map<int,unordered_map<int,int>> um;

    int free_zeros = 0, max_c_zeros = 0;
    for(int i = 0; i<n; i++){
        int sign_a = (a[i]<0?-1:1);

        int sign_b = (b[i]<0?-1:1);

        int sign = -1 * sign_a * sign_b;

        int factor = __gcd(abs(a[i]),abs(b[i]));

        int key = sign * (abs(b[i])/factor);
        int val = abs(a[i])/factor;
        
        if(a[i] ==0 && b[i] ==0){
            free_zeros++;
            continue;
        }
        if(a[i]==0) continue;

        if(um.find(key)!=um.end()){
            unordered_map<int,int>& val_req = um[key];
            val_req[val]++;
        }
        else{
            um[key][val]++;
        }

        // cout<<key<<" "<<val<<" "<<um[key][val]<<" "<<factor<<endl;
        max_c_zeros = max(um[key][val], max_c_zeros);
    }

    cout<<free_zeros + max_c_zeros<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}