#include <bits/stdc++.h>
using namespace std;

int msb_index(unsigned x){

	return 31 - __builtin_clz(x);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		unsigned a, b;
		cin>>a>>b;

		int ka = msb_index(a);
		int kb = msb_index(b);

		if(a==b){
			cout<<0<<endl;
			continue;
		}
		if(kb>ka){
			cout<<-1<<endl;
			continue;
		}

		unsigned FULL = (ka==31) ? 0xFFFFFFFFu : ((1<<(ka+1))-1);

		unsigned x1 = (~a) & FULL;

		unsigned x2 = (~b) & FULL;

		vector<unsigned> ops;
		if(x1) ops.push_back(x1);
		if(x2) ops.push_back(x2);

		cout<<ops.size()<<endl;
		if(!ops.empty()){
			for(auto v : ops) cout<<v<<" ";
			cout<<"\n";
		}
	}

}
