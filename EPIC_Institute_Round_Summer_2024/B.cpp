#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        cin>>n;

        vector<int> a(n);

        // Read elements
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int prev_max=a[0], max_diff = 0, total=0;
        for(int i = 1; i<n; i++){
            if(a[i]<prev_max){
                int diff = prev_max - a[i];
                total+=diff;
                max_diff = max(diff, max_diff);
            }
            prev_max = max(prev_max,a[i]);
        }

        int ans = total + max_diff;
        cout<<ans<<"\n";
    
    }

    return 0;
}
