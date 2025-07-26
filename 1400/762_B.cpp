#include <bits/stdc++.h>
using namespace std;

void solve(){
    int usb_num, ps_2_num, both;
    cin>>usb_num>>ps_2_num>>both;
    int num_mouses_available;
    cin>>num_mouses_available;
    vector<int> usb;
    vector<int> ps_2;
    for(int i = 0; i<num_mouses_available; i++){
        int cost; string typ;
        cin>>cost;
        cin>>typ;
        if(typ=="USB"){
            usb.push_back(cost);
        }
        else{
            ps_2.push_back(cost);
        }
    }
    long long total_cost = 0;
    sort(usb.begin(), usb.end());
    sort(ps_2.begin(), ps_2.end());
    int i = 0, j = 0;
    int n = usb.size(), m = ps_2.size();
    int num_mouses = 0;
    while((i<n && j<m) && (usb_num>0 || both>0) && (ps_2_num>0 || both>0)){
        if( (usb[i]<=ps_2[j]) && (usb_num>0 || both>0)){
            if(usb_num>0) usb_num--;
            else both--;
            total_cost+=usb[i];
            num_mouses++;
            i++;
        }
        else if((usb[i]>ps_2[j]) && (ps_2_num>0 || both>0)){
            if(ps_2_num>0) ps_2_num--;
            else both--;
            total_cost+=ps_2[j];
            num_mouses++;
            j++;
        }
    }
    while(i<n){
        if(usb_num>0){
            usb_num--;
            total_cost+=usb[i];
            num_mouses++;
        }
        else if(both>0){
            both--;
            total_cost+=usb[i];
            num_mouses++;
        }
        i++;
    }
    while(j<m){
        if(ps_2_num>0){
            ps_2_num--;
            total_cost+=ps_2[j];
            num_mouses++;
        }
        else if(both>0){
            both--;
            total_cost+=ps_2[j];
            num_mouses++;
        }
        j++;
    }

    cout<<num_mouses<<" "<<total_cost<<endl;

    // check if i, j are not at the end and the nums are not 0.
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}