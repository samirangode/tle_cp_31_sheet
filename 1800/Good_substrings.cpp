#include <bits/stdc++.h>

using namespace std;

int main(){
    // find all substrings in a naive way for a given string

    // string s = "abcd";
    string s;
    cin>>s;

    string good;
    cin>>good;

    int k;
    cin>>k;


    int n = s.length();
    int p = 31;
    int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for(int i = 0; i<n; i++){
        p_pow[i] = (p_pow[i-1]*p)%m;
    }
    vector<long long> h(n+1);
    for(int i = 0; i<n; i++){
        h[i+1] = (h[i] + (s[i]-'a'+1)*p_pow[i])%m;
    }
    // unordered_set<string> us;
    // for(int i=0; i<n; i++){
    //     string temp = "";
    //     int bad_count = 0;
    //     for(int j=i; j<n; j++){
    //         temp+=s[j];
    //         if(good[s[j]-'a']=='0'){
    //             bad_count++;
    //         }
    //         if(bad_count<=k)
    //             us.insert(temp);
    //         else
    //             break;
    //     }
    // }
    vector<int> bad_prefix(n+1);
    // if(good[s[0]-'a']=='0'){
    //     bad_prefix[0] = 1;
    // }
    for(int i = 1; i<=n; i++){
        if(good[s[i-1]-'a']=='0'){
            bad_prefix[i] = bad_prefix[i-1] + 1;
        }
        else{
            bad_prefix[i] = bad_prefix[i-1];
        }
    }
    int cnt = 0;
    for(int l = 1; l<=n; l++){
        unordered_set<long long> hs;
        for(int i = 0; i<=n-l; i++){
            long long cur_h = (h[i+l] + m - h[i])%m;
            int total_bad_num = bad_prefix[i+l] - bad_prefix[i];
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            if(total_bad_num<=k)
                hs.insert(cur_h);
        }
        cnt+=hs.size();
    }
    // cout<<"distinct substrings: "<<us.size()<<endl;

    // cout<<"all the substrings: "<<endl;
    // for(auto it: us){
    //     cout<<it<<endl;
    // }
    cout<<cnt<<endl;
}

