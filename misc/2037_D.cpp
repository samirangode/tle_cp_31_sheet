#include <bits/stdc++.h>

using namespace std;

void run() {
    int n, m, L;
    cin>>n>>m>>L;
    vector<pair<int,int>> hurdles(n);
    for(int i = 0; i<n; i++){
        int li, ri;
        cin>>li>>ri;
        hurdles[i] = {li,ri};
    }
    // vector<pair<int,int>> Pup(m);
    vector<int> power_loc(m), power_val(m);
    for(int j = 0; j<m; j++){
        int xi, vi;
        cin>>xi>>vi;
        // Pup[j]={xi,vi};
        power_loc[j] = xi;
        power_val[j] = vi;
    }
    int total_power_ups = 0;
    int prev_pup_ind = -1;
    int v_curr = 1;
    priority_queue<int> pq;
    for(int i = 0; i<n; i++){
        
        int right = hurdles[i].second;
        int left = hurdles[i].first;
        if(v_curr < (right - left + 2)){
            int ind = lower_bound(power_loc.begin(),power_loc.end(),hurdles[i].first) - power_loc.begin();
            if(ind==0){
                cout<<-1<<endl; return;
            }
            ind-=1;
            for(int j = (prev_pup_ind+1); j<=ind; j++){
                pq.push(power_val[j]);
            }
            prev_pup_ind = ind;
            while(!pq.empty() && v_curr<(right-left+2)){
                int val = pq.top(); 
                pq.pop();
                v_curr+=val;
                total_power_ups+=1;
            }
            if(v_curr<(right-left+2)){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<total_power_ups<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        run();
    }
}