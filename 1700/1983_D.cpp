#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& a, int l, int r) {
    if(r-l<=0) return 0;
    int m = l + (r-l)/2;
    long long inv = 0;
    inv+=mergeAndCount(a, l, m);
    inv+=mergeAndCount(a, m+1, r);

    vector<int> temp;
    temp.reserve(r-l+1);
    int i = l, j = m+1;
    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            inv+=(m - i + 1);
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i<=m){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(a[j]);
        j++;
    }
    for(int k = 0; k <(int)temp.size(); k++){
        a[l + k] = temp[k];
    }
    return inv;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    vector<int> a_copy = a;

    vector<int> b_copy = b;
    long long inv_count_a = mergeAndCount(a_copy, 0, n - 1);
    long long inv_count_b = mergeAndCount(b_copy, 0, n - 1);

    if(inv_count_a % 2 != inv_count_b % 2){
        cout<<"NO"<<endl;
        return;
    }
    
    // check if multiset of a and b are same
    if(a_copy==b_copy){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}