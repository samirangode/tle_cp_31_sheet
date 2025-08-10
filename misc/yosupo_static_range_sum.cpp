#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    cin>>n>>q;
    vector<long long> a(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<long long> prefix_sum(n);
    partial_sum(a.begin(), a.end(), prefix_sum.begin());
    vector<long long> ans(q);
    for(long long i = 0; i<q; i++){
        long long l, r;
        cin>>l>>r;
        long long left_side = 0;
        if(l==0) left_side = 0;
        else left_side = prefix_sum[l-1];
        long long right_side = prefix_sum[r-1];
        ans[i] = right_side - left_side; 
    }
    for(long long val : ans){
        cout<<val<<endl;
    }
}
