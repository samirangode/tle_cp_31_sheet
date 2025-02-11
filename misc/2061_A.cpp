#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int numOdd = 0, numEven = 0;
    for(int i = 0; i< n; i++){
        cin>>a[i];
        if(a[i]&1){
            numOdd++;
        }
        else{
            numEven++;
        }
    }
    int ans = 0;
    if(numEven){
        ans = numOdd+1;
    }
    else{
        ans = max(numOdd - 1, 0);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
