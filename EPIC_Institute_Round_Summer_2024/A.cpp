#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        cin>>k;

        int ans = (n-1)*k + 1;

        cout<<ans<<"\n";
    
    }

    return 0;
}
