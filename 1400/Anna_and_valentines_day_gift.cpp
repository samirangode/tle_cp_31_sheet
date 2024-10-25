#include <bits/stdc++.h>

using namespace std;


const int MAXN = 200200;

string arr[MAXN];
int n, m;
int len[MAXN], zrr[MAXN];

void build(){
    memset(zrr, 0, sizeof(zrr));
    for(int i=0; i<n; ++i){
        len[i] = arr[i].size();
        for(auto it = arr[i].rbegin(); it!=arr[i].rend() &&
        *it == '0'; it++){
            ++zrr[i];
        }
    }
}

string solve(){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans+=len[i]-zrr[i];
    }
    sort(zrr, zrr+n);
    reverse(zrr, zrr+n);
    for(int i =0; i<n; i++){
        if(i&1) ans+=zrr[i];
    }
    return (ans - 1 >=m ? "Sasha" : "Anna");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        cin>>n;
        cin>>m;

        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        build();
        cout<<solve()<<endl;
    }
}
