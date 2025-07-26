#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> nums(n);
    iota(nums.begin(),nums.end(), 1);
    int i = 0, j = n-1;
    vector<int> ans(n);
    for(int k = n-2; k>=0; k--){
        if(s[k]=='<'){
            ans[k+1] =  nums[i];
            i++;
        }
        else{
            ans[k+1] = nums[j];
            j--;
        }
    }
    ans[0] = nums[i];
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}
