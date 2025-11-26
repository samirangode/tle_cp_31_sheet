#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> um;
    for(int i=0; i<n; i++){
        cin>>a[i];
        um[a[i]]++;
    }
    if(um.size()<=2){
        bool possible = true;
        if(um.size()==2){
            vector<int> count;
            for(auto it : um){
                count.push_back(it.second);
            }
            sort(count.begin(),count.end());
            if((count[1]-count[0])>1){
                possible=false;
            }
        }
        if(possible){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}