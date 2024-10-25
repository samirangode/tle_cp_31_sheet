#include <bits/stdc++.h>

using namespace std;


bool solve(vector<vector<int>> & ds, vector<pair<int,int>>& domino){
    bool possible = true;
    for(pair<int,int> p : domino){
        int a = p.first;
        int b = p.second;
        if(a==b){
            possible =false;
            break;
        }
        // check if less than 2
        if(ds[a].size()==2 || ds[b].size()==2){
            possible = false;
            break;
        }
        // if(ds[a].size()>0){
        //     if(ds[ds[a][0]].size()==2){
        //         possible = false;
        //         break;
        //     }
        // }
        // if(ds[b].size()>0){
        //     if(ds[ds[b][0]].size()==2){
        //         possible = false;
        //         break;
        //     }
        // }
        if(ds[a].size()>0 && ds[b].size()>0){
            if(ds[a][0]==ds[b][0]){
                possible=false;
                break;
            }
        }
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    // cout<<"DEBUG "<<possible<<endl;
    // cout<<"DEBUG PRINTING DOMINO "<<endl;
    // for(int i = 0; i<domino.size(); i++ ){
    //     cout<<domino[i].first<<" "<<domino[i].second<<endl;
    // }
    // cout<<"DEBUG PRINTING DS "<<endl;
    // for(int i=1;i<=domino.size(); i++){
    //     cout<<i<<" ";
    //     if(ds[i].size()==1)
    //     cout<<ds[i][0]<<" ";
    //     if(ds[i].size()==2)
    //     cout<<ds[i][1]<<" ";
    //     cout<<endl;
    // }

    return possible;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>> domino;
        for(int i = 0; i<n; i++){
            int a,b;
            cin>>a;
            cin>>b;
            domino.push_back({a,b});
        }
        vector<vector<int>> ds(n+1);
        bool ans = solve(ds, domino);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
    }
}