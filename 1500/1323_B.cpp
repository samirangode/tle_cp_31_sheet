#include <bits/stdc++.h>

using namespace std;

struct RunData{
    vector<int> runs;
    vector<long long> sufSum;
    vector<int> sufCnt;
};

RunData buildData(const vector<int>& arr){
    vector<int> runs;
    int n = arr.size();
    int cur = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]==1){
            cur++;
        }
        else{
            if(cur>0) runs.push_back(cur);
            cur = 0;
        }
    }
    if(cur>0) runs.push_back(cur);

    sort(runs.begin(), runs.end());
    int R = runs.size();
    vector<long long> sufSum(R+1,0);
    vector<int> sufCnt(R+1, 0);
    for(int i = R -1 ; i>=0; i--){
        sufSum[i] = sufSum[i+1] + runs[i];
        sufCnt[i] = sufCnt[i+1] + 1;
    }

    return {runs, sufSum, sufCnt};
}

long long countLensFast(const RunData& d, int len){
    const auto& runs = d.runs;
    const auto& sufSum = d.sufSum;
    const auto& sufCnt = d.sufCnt;
    int R = runs.size();
    int idx = lower_bound(runs.begin(), runs.end(), len) - runs.begin();
    if(idx==R) return 0;

    long long sumL = sufSum[idx];
    long long cnt = sufCnt[idx];

    return sumL - 1LL * (len - 1) * cnt;
}

void solve(){
    int n, m;
    long long k;
    cin>>n>>m>>k;

    vector<int> a(n);
    vector<int> b(m);

    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;

    RunData A = buildData(a);
    RunData B = buildData(b);

    long long ans = 0;

    for(long long p = 1; p*p <=k; ++p){
        if(k%p != 0 ) continue;

        long long q = k /p;

        if(p<=n && q<=m){
            ans+=countLensFast(A, (int) p) * countLensFast(B, (int) q);
        }
        if(p!=q && q<=n && p<=m){
            ans+=countLensFast(A, (int) q) * countLensFast(B, (int) p);
        }
    }
    cout<<ans<<endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        solve();
    }
}