#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    int a = 0, b= 0, c=0;
    for(int i = 0; i<n; i++){
        cin>>a;
        cin>>b;
        cin>>c;
        if((a+b+c)>=2) ans++;
    }
    cout<<ans<<endl;
}
