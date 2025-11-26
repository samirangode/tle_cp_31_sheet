#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(), x.end());
    int gc = 0;
    for(int i=0, j=n-1; i<j;){
        if((x[i] + x[j]) == k){
            gc++;
            i++; j--;
        }
        else if((x[i] + x[j])>k){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<gc<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}