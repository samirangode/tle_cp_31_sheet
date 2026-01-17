#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<long long> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    long long sum = 0;
    for(auto x : a) sum+=x;

    if(sum&1){
        cout<<"NO"<<endl;
        return 0;
    }
    sort(a.begin(), a.end());
    long long maxe = a[n-1];

    if(maxe<=(sum/2)){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;


}