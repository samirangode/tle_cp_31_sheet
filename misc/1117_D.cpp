#include <bits/stdc++.h>

using namespace std;

// #define long long ll
typedef long long ll;
static const ll MOD = 1e9 + 7;

vector<vector<ll>> multiplyMatrix(vector<vector<ll>>& A,
                                  vector<vector<ll>>& B, int M){

    vector<vector<ll>> C(M, vector<ll>(M,0));
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            __int128_t temp = 0; // to avoid 64 bit overflow
            for(int k = 0; k<M; k++){
                temp += (__int128_t)A[i][k] * B[k][j];
            }
            C[i][j] = (ll)(temp%MOD);
        }
    }
    return C;
}


vector<vector<ll>> matrixPower(vector<vector<long long>> base, 
                                        long long exp, int M){
    
    vector<vector<ll>> result(M, vector<ll>(M,0));
    for(int i = 0; i<M; i++){
        result[i][i] = 1ll;
    }
    // exponentiation logic
    while(exp>0){
        if(exp&1){
            result = multiplyMatrix(result, base, M);
        }
        // base = base * base;
        base = multiplyMatrix(base, base, M);
        exp = exp>>1;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin>>N>>M;

    if(N<M){
        cout<<1<<endl;
        return 0;
    }

    // Now we do the matrix exponentiation
    // Build the transition matrix
    vector<vector<ll>> trans(M,vector<ll>(M,0));
    trans[0][0] = 1; trans[0][M-1]=1;
    // subdiagonal = 1
    for(int i = 1; i<M; i++){
        trans[i][i-1] = 1;
    }

    // Now raise it to the power exponent using matrix exponentiation
    // I need only N-(M-1) because that'll give me d[N-1]
    long long exponent = N-M+1;

    vector<vector<ll>> transExp = matrixPower(trans, exponent, M);

    // Now we multiply the trans with the initial column vector to get the value
    // But in our case the vector V is all ones so we just need the sum of the
    // first row
    long long ans = 0; 
    for(int i = 0; i<M; i++){
        ans = (ans + transExp[0][i])%MOD;
    }

    cout<<ans<<endl;
    return 0;

}
