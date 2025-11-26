#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_DIFF = 4e5 + 5;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin>>n>>m>>q;

    vector<int> a(n), b(m);
    ll asum = 0, bsum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        asum+=a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
        bsum+=b[i];
    }
    vector<bool> possibleA_pos(MAX_DIFF,false), possibleA_neg(MAX_DIFF, false);
    for(int i = 0; i<n; i++){
        ll diff = asum - a[i];
        if(abs(diff)<MAX_DIFF){
            if(diff<0){
                possibleA_neg[-diff] = true;
            }
            else{
                possibleA_pos[diff] = true;
            }
        }
    }

    vector<bool> possibleB_pos(MAX_DIFF, false), possibleB_neg(MAX_DIFF, false);
    for(int j = 0; j<n; j++){
        ll diff = bsum - b[j];
        if(abs(diff)<MAX_DIFF){
            if(diff<0){
                possibleB_neg[-diff] = true;
            }
            else{
                possibleB_pos[diff] = true;
            }
        }
    }

    vector<bool> possPos(MAX_DIFF, false), possNeg(MAX_DIFF, false);
    for(int i = 1; i < MAX_DIFF; i++){
        for(int j = 1; j < MAX_DIFF; j++){
            if((long long)i*j >= MAX_DIFF) break;

            if(possibleA_pos[i] && possibleB_pos[j]){
                possPos[i*j] = true;
            }
            if(possibleA_neg[i] && possibleB_neg[j])
                possPos[i*j] = true;
            
            if(possibleA_pos[i] && possibleB_neg[j])
                possNeg[i*j] = true;
            
            if(possibleA_neg[i] && possibleB_pos[j])
                possNeg[i*j] = true;
        }
    }

    while(q--){
        long long x;
        cin >> x;
        if(x>0)
            cout<<(possPos[x] ? "YES" : "NO")<<endl;
        else
            cout<<(possNeg[-x] ? "YES" : "NO")<<endl;
    }

    return 0;

}
