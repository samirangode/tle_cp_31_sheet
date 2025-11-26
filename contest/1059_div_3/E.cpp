#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];	
	}
	vector<int> freq(n+1,0);
	for(int i = 0; i<n; i++) freq[a[i]]++;

	using P = pair<int,int>;
	priority_queue<P, vector<P>, greater<P>> pq;

	for(int v = 1; v<=n; v++) pq.push({freq[v], v});

	vector<int> ans;
	ans.reserve(k);

	int last = a[n-1];
	int last2 = a[n-2];
	for(int step = 0; step<k; step++){
		vector<P> hold; hold.reserve(2);

		P pick = {-1,-1};
		while(!pq.empty()){
			auto cur = pq.top(); pq.pop();
			int f = cur.first; int v = cur.second;
			if(v != last && v!=last2){
				pick = cur;	
			}
			else{
				hold.push_back(cur);
			}
		}

		for(auto &e : hold) pq.push(e);

		
		ans.push_back(pick.second);

		pq.push({pick.first+1, pick.second});

		last2 = last;
		last = pick.second;
		
	}

	for(int val : ans){
		cout<<val<<" ";	
	}
	cout<<endl;

}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin>>t;
while(t--){
	solve();
}


}
