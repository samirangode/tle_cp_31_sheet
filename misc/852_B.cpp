#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;


vector<ll> poly_mult(const vector<ll>& p,
                     const vector<ll>& q,
                     int m){

vector<ll> res(m,0);
for(int i = 0; i<m; i++){
    for(int j = 0; j<m; j++){
        res[(i+j)%m] = (res[(i+j)%m] + p[i]*q[j])%MOD;
    }
}

return res;
}

vector<ll> poly_exp(vector<ll> base, ll exp, int m){
    vector<ll> result(m,0);
    result[0] = 1;
    while(exp>0){
        if(exp&1){
            result = poly_mult(result, base, m);
        }
        base = poly_mult(base, base, m);
        exp >>=1;
    }

    return result;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, m;
    cin>>n>>L>>m;

    vector<int> entryCosts(n), midCosts(n), exitCosts(n);
    vector<ll> freq_entry(m,0), freq_mid(m,0), freq_exit(m,0);

    for(int i = 0; i<n; i++){
        cin>>entryCosts[i];
        freq_entry[entryCosts[i]%m]++;
    }
    for(int i = 0; i<n; i++){
        cin>>midCosts[i];
        freq_mid[midCosts[i]%m]++;
    }
    for(int i = 0; i<n; i++){
        cin>>exitCosts[i];
        int combined = (midCosts[i] + exitCosts[i])%m;
        freq_exit[combined]++;
    }

    L-=2;

    vector<ll> trans = poly_exp(freq_mid, L, m);

    vector<ll> left = poly_mult(freq_entry, trans, m);

    vector<ll> result = poly_mult(left, freq_exit, m);

    cout<<result[0]%MOD<<endl;
}