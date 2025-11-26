#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), pos, neg;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] >= 0) {
                pos.push_back(a[i]);
            } else {
                neg.push_back(a[i]);
            }
        }
        sort(pos.begin(), pos.end(), greater<int>());
        sort(neg.begin(), neg.end());

        if(neg.empty()){
            cout<< "No"<<"\n";
        }
        else{
            cout << "Yes\n";
            vector<int> ans;
            long long prefix_sum = 0;
            size_t pos_index = 0, neg_index = 0;

            while (ans.size() < n) {
                if (prefix_sum <= 0) {
                    if (pos_index < pos.size()) {
                        ans.push_back(pos[pos_index++]);
                        prefix_sum += ans.back();
                    }
                } else {
                    if (neg_index < neg.size()) {
                        ans.push_back(neg[neg_index++]);
                        prefix_sum += ans.back();
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                cout << ans[i] << (i < n - 1 ? ' ' : '\n');
            }
        }
    }
}
