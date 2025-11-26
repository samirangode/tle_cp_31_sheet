#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
    int n;
    cin>>n;

    vector<string> cad(n);
    vector<vector<int>> vot(2, vector<int>(n+8));

    for(int k = 0; k<2; k++){
        cin>>cad[k];

        for(int i = 0; i<n; i++){
            if(cad[k][i]=='A'){
                vot[k][i+1] = 1;
            }
        }
    }

    vector<vector<int>> dp(n+9, vector<int>(3,-1));
    dp[0][0] =0;
    
    for(int k = 0; k<=n-1; k++){

        for(int i=0; i<3; i++){

            if(dp[k][i]!=-1){
                int vt = 0, val = dp[k][i];

                if(i==0){
                    vt = (vot[0][k+1] + vot[0][k+2] + vot[0][k+3])/2 + (vot[1][k+1] + vot[1][k+2] + vot[1][k+3])/2;

                    dp[k+3][0] = max(vt+val, dp[k+3][0]);

                    vt = (vot[1][k+1] + vot[0][k+1] + vot[0][k+2])/2;

                    dp[k+1][1]=max(vt+val,dp[k+1][1]);
                    vt=(vot[1][k+1]+vot[1][k+2]+vot[0][k+1])/2;
                    dp[k+1][2]=max(vt+val,dp[k+1][2]);

                }
                if(i==1)
                {
                // **
                // *
                vt=(vot[0][k+2]+vot[0][k+3]+vot[0][k+4])/2+(vot[1][k+1]+vot[1][k+2]+vot[1][k+3])/2;
                dp[k+3][1]=max(vt+val,dp[k+3][1]);
                vt=(vot[1][k+1]+vot[1][k+2]+vot[0][k+2])/2;
                dp[k+2][0]=max(vt+val,dp[k+2][0]);
                }
                if(i==2)
                {
                //*
                //**
                vt=(vot[1][k+2]+vot[1][k+3]+vot[1][k+4])/2+(vot[0][k+1]+vot[0][k+2]+vot[0][k+3])/2;
                dp[k+3][2]=max(vt+val,dp[k+3][2]);
                vt=(vot[0][k+1]+vot[0][k+2]+vot[1][k+2])/2;
                dp[k+2][0]=max(vt+val,dp[k+2][0]);
                }

            }
        }
    }

    cout<<dp[n][0]<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}