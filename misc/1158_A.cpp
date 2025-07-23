#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> boys(n);
    vector<int> girls(m);
    for(int i = 0; i<n; i++){
        cin>>boys[i];
    }
    for(int j = 0; j<m ;j++){
        cin>>girls[j];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    long long precomp = 0;
    for(int i = 0; i<n; i++){
        precomp+=boys[i];
    }
    long long ans = 0;
    bool possible = true;
    for(int j = m-1; j>=1; j--){
        long long diff = girls[j] - boys[n-1];
        if(diff<0){
            possible = false;
            break;
        }
        long long val = diff + precomp;
        ans+=val;
    }
    
    if(girls[0]<boys[n-1]){
        possible =false;
    }
    
    if(!possible){
        cout<<-1<<endl;
        return 0;
    }
    // for j = 0
    if(girls[0]==boys[n-1]){
        ans+= precomp;
    }
    else{
        ans += girls[0] - boys[n-2] + precomp;
    }
    cout<<ans<<endl;
    
}
