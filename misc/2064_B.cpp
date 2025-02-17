#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    unordered_map<int,int> um; 
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        um[a[i]]++;
    }
    int max_len = -1, l_max = 0, r_max=0;
    int i = 0;
    while(i<n){
        if(um[a[i]]==1){
            int l_temp = i, r_temp = i;
            while(r_temp<n && um[a[r_temp]]==1){
                r_temp++;
            }
            i=r_temp;
            if((r_temp - l_temp)>max_len){
                r_max = r_temp-1;
                l_max = l_temp;
                max_len = r_max - l_max + 1;
            }
        }
        else{
            i++;
        }
    }

    if(max_len==-1){
        cout<<0<<endl;
    }
    else{
        cout<<l_max+1<<" "<<r_max+1<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}