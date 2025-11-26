#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int solve(vector<int>& a, vector<int>& b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int s = 0, i = n-1, j = n-1;
    // cout<<"in solve"<<endl;
    while((s<n) && (j>=s) && (i>=0)){
        // cout<<i<<" "<<j<<" "<<s<<endl;
        if((i>=0) && (s<n) && 
              (j==(n-1)) && (a[i]>=b[j])){
                i--; s++;
                // DEBUG
                // cout<<"inside first if statement"<<endl;
                // cout<<i<<" "<<j<<" "<<s<<endl;
                // DEBUG
                continue;
        }
        if(s==n){
            break;
        }
        if(a[i]>=b[j]){
            j++; s++;
        }
        else{
           j--; i--; 
        }
    }
    return s;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        // debug
        // cout<<"in test case " <<t<<endl;
        // debug
        cin>>n;
        cin>>m;
        vector<int> a(n);
        vector<int> b(n);
        a[0] = 1;
        for(int i = 1; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
        
        int ans = solve(a,b);
        cout<<ans<<"\n";
    }

    return 0;
}
