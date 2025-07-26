#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    bool possible = false;
    for(int i = 0; i<(n-1); i++){
        for(int j = i+1; j<n; j++){
            if(__gcd(a[i],a[j])<=2){
                possible = true;
            }
        }
    }
    if(possible){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
