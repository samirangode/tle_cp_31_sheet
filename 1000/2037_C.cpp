#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n<=4){
        cout<<-1<<endl;
        return;
    }
    vector<int> odd;
    vector<int> even;

    for(int i = 1;i<=n; i=i + 2){
        odd.push_back(i);
    }
    for(int i = 2; i<=n; i=i+2){
        even.push_back(i);
    }

    int last_odd_ele = odd.back();
    if(last_odd_ele%2 == 0){
        swap(even[0],even[2]);
    }
    else if(last_odd_ele%2 == 2){
        swap(even[0], even[1]);
    }
    
    for(int i : odd){
        cout<<i<<" ";
    }
    for(int i : even){
        cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
