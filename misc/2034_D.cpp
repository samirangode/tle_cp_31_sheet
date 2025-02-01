#include <bits/stdc++.h>

using namespace std;

void run(){
    int n;
    cin>>n;
    vector<int> num(n);
    
    for(int i = 0; i<n; i++){
        cin>>num[i];
    }
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for(int i = 0; i<n; i++){
        if(num[i]==0) count_0++;
        if(num[i]==1) count_1++;
        if(num[i]==2) count_2++;
    }
    vector<int> ord_num(n);
    int num0 = 0, num1= 0, num2=0;
    for(int i = 0; i<n; i++){
        if(num0<count_0){
            ord_num[i] = 0; num0++; continue;
        }
        if(num1<count_1){
            ord_num[i] = 1; num1++; continue;
        }
        if(num2<count_2){
            ord_num[i] = 2; num2++; continue;
        }
    }
    queue<int> q0, q1, q2;
    for(int i = 0; i<n; i++){
        if(num[i]!=ord_num[i]){
            if(num[i]==0) q0.push(i);
            if(num[i]==1) q1.push(i);
            if(num[i]==2) q2.push(i);
        }
    }
    int num_ans = 0;
    // queue<pair<int,int>> ans_moves;
    vector<pair<int,int>> ans_moves;
    while(!q1.empty()){
        num_ans++;
        int loc1 = q1.front();
        q1.pop();
        int loc_ele;
        if(ord_num[loc1]==0) loc_ele = q0.front(), q0.pop();
        if(ord_num[loc1]==2) loc_ele = q2.front(), q2.pop();
        ans_moves.push_back({loc1+1,loc_ele+1}); 
        if(ord_num[loc_ele]!=1) q1.push(loc_ele);
    }
    cout<<num_ans<<endl;
    // for(int i=num_ans-1; i>=0; i--){
    //     cout<<ans_moves[i].first<<" "<<ans_moves[i].second<<endl;
    // }
    for(int i = 0; i<num_ans; i++){
        cout<<ans_moves[i].first<<" "<<ans_moves[i].second<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        run();
    }

}
