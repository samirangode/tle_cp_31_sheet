#include <bits/stdc++.h>

using namespace std;

int n;

bool check(int n, vector<pair<int,int>> &segments, int k){
    int ll = 0, rr = 0;

    for(int i = 0; i<n ;i++){
        ll = max(ll-k, segments[i].first);
        rr = min(rr+k, segments[i].second);
        if(ll>rr){
            return false;
        }
    }
    return true;
}

int solve(int n, vector<pair<int,int>> &segments){
   int l = -1, r = 1e9; 
   while((r-l)>1){
        int mid = l + (r-l)/2;
        if(check(n,segments,mid)){
            r = mid;
        }
        else{
            l = mid; 
        }
   }
   return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> segments(n); 

        for(int i = 0; i<n; i++){
            cin>>segments[i].first;
            cin>>segments[i].second;
        }
        int ans = solve(n,segments);
        cout<<ans<<endl;
    }
}
