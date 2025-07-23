#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , k;
    cin>>n>>k;
    vector<int> a(n);
    
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    if(k>=2){
        cout<<"YES"<<endl;
        return;
    }
    // k = 1
    bool possible = true;
    for(int i = 1; i<n; i++){
        if(a[i]< a[i-1]){
            possible = false;
            break;
        }
    }
    if(possible)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}


int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin>>t;
   while(t--){
    solve();
   }

}
