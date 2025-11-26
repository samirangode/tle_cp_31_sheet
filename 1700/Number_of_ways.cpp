#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin>>n;

    vector<long long> a(n);
    long long sum = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }

    long long k = sum/3;
    long long k2 = 2*k;

    if(n<3){
        cout<<0<<endl;
        return 0;
    }

    if(sum%3 !=0 ){ 
        cout<<0<<endl;
        return 0;
    }

    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];

    for(int i = 1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    vector<long long> k2_on_the_right(n);
    k2_on_the_right[n-1] = 0;
    k2_on_the_right[n-2] = 0;
    for(int i = n-3; i>=0; i--){
        k2_on_the_right[i] = k2_on_the_right[i+1];
        if(prefix_sum[i+1]==k2){
            k2_on_the_right[i] +=1; 
        }
    }

    long long num_of_ways = 0;

    for(int i = 0; i<n; i++){
        if(prefix_sum[i] == k){
            num_of_ways += k2_on_the_right[i];
        }
    }

    cout<<num_of_ways<<endl;
    return 0;

}
