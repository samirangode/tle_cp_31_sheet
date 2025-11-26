#include <bits/stdc++.h>

using namespace std;

bool ok(int x, vector<int>& a, vector<int>& b){
    int n = a.size();
    int c = 0;
    for(int i = 0; i<n; i++){
        if((c<=b[i]) && ((x-1-c)<=a[i])) c++;
    }
    return c>=x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i<n; i++){
            cin >> a[i] >> b[i];
        }

        int l = 0, r = n, mid;
        int ans = 0;
        while(l<=r){
            // cout<<l<<" "<<r<<endl;
            mid = l + (r-l)/2;
            if(ok(mid, a, b)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<"\n";
    }
}
