#include <bits/stdc++.h>

using namespace std;

int n;

int minPenalty(vector<int>& arr){
    int n = arr.size();
    if (n<=2){
        return 0;
    }
    // int small = min(arr[0], arr[1]);
    // int big = max(arr[0],arr[1]);
    int small = arr[0];
    int big = 0;
    int penalty = 0;
    for(int i = 1; i<n; i++){
        if(arr[i]<=small && big==0){
            small = arr[i];
            continue;
        } 
        if(arr[i]>small && big==0){
            big = arr[i];
            continue;
        }
        // if arr[i] is smaller than both s and t
        // then arr[i] will be sent to whichever is the smallest
        if((arr[i]<=small)){
           small = arr[i];
        }
        // if arr[i] is greater than one of them but smaller than the other
        // 1st case smaller than t but bigger than s
        else if((arr[i]>small)&&(arr[i]<=big)){
            big = arr[i];
        }
        else{
            small = big;
            big = arr[i];
            penalty+=1;
        }
    }
    return penalty;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        cin>>n;
        vector<int> arr(n); 
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int ans = minPenalty(arr);
        cout<<ans<<endl;
    }
}