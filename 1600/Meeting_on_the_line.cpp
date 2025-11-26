#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> x(n);
        vector<int> t(n);
         
        for(int i = 0; i<n; i++){
            cin>>x[i];
        }
        for(int i = 0; i<n; i++){
            cin>>t[i];
        }

        int min_coord = INT_MAX;
        int max_coord = INT_MIN;

        for(int i = 0; i<n; i++){
            min_coord = min(x[i]-t[i], min_coord);
            max_coord = max(x[i]+ t[i], max_coord);
        }
        int sum = min_coord + max_coord;
        cout<< sum/2;
        if(sum%2 != 0){
            cout<<".5";
        }
        cout<<"\n";
    }
    

    return 0;
}
