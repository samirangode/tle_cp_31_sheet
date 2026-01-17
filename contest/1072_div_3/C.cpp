#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, k;
	cin>>n>>k;
	if(n==k){
        cout<<0<<endl;
        return;
    }
    // bfs
    queue<int> q;
    q.push(n);
    int level = 0;
    int sz = q.size();
    unordered_set<int> visited;
    visited.insert(n);
    
    while(!q.empty()){
        sz = q.size();
        while(sz--){
            int curr = q.front();
            q.pop();
            
            int num1 = curr/2;
            int num2 = num1;
            if(curr&1){
               num2 = num1 + 1; 
            }
            
            if(num1>1 && visited.find(num1)== visited.end()){ 
                q.push(num1);
                visited.insert(num1);
            }
            if(num2>1 && visited.find(num2)== visited.end()){ 
                q.push(num2);
                visited.insert(num2);
            }
            if(num1==k || num2==k){
                cout<<level+1<<endl;
                return;
            }
        }
        level++;
    }
    cout<<-1<<endl;
    
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