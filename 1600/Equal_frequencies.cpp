#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<vector<int>> indices(26);
        for(int i=0; i<n; i++  ){
            indices[s[i]-'a'].push_back(i);
        }
        vector<int> order(26);
        iota(order.begin(), order.end(),0);
        sort(order.begin(), order.end(), [&](int left, int right){
            return indices[left].size()>indices[right].size();
        });

        string result;
        int bestMatch = -1;
        for(int count= 1; count<=26; count++){
            if(n%count==0){
                int currentMatches = 0;
                for(int i = 0; i<count; i++){
                    currentMatches += min(n/count, (int)indices[order[i]].size());
                }

                if(currentMatches>bestMatch){
                    bestMatch = currentMatches;
                    result = string(n, ' ');
                    vector<int> leftovers;
                    for(int i = 0;i<count; i++){
                        int charIndex = order[i];
                        for(int j = 0; j<(n/count); j++){
                            if (j < (int)indices[charIndex].size()) {
                                result[indices[charIndex][j]] = 'a' + charIndex;
                            } else {
                                leftovers.push_back('a' + charIndex);
                            }
                        }
                    }
                    for (char &c : result) {
                        if (c == ' ') {
                            c = leftovers.back();
                            leftovers.pop_back();
                        }
                    }
                }
            }
        }
        cout << n - bestMatch << '\n' << result << '\n';
    }

    return 0;
}
