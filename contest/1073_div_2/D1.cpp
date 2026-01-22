#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	string s;
    cin>>s;
    // find the first occurrence of ')'
    int first_close = -1;
    for(int i = 0; i<n; i++){
        if(s[i]==')'){
            first_close = i;
            break;
        }
    }
    int count = 0;
    for(int j = first_close+1; j<n; j++){
        if(s[j]=='('){
           count++;
           if(count>1){
            break;
           }
        }
    }
    if(count>1){
        cout<<n-2<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}