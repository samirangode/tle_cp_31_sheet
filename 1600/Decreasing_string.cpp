// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// char solve(string& s,ll& pos){
//     pos--;
//     // calculate which string will pos be a part of

//     ll curLen = s.size(); 
//     bool ok = pos<curLen;
        

//     stack<char> st;
//     for(auto c : s){
//         if(s.empty() || st.top()<=c){
//             st.push(c);
//         }
//         else{
//             while(st.top()>c){
//                 st.pop();
//                 pos-curLen;
//                 curLen--;
//                 if(pos<curLen){
//                     ok = true;
//                 }
//             }
//         }
//     }
    
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     while(t--){
//         string s;
//         ll pos;
//         cin>>s;
//         cin>>pos;        
//         char ans = solve(s, pos);
//         cout<<ans;
//     }
// }
#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

int t;

int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        string s;
        long long pos;
        cin >> s >> pos;
        --pos;
        
        int curLen = s.size();
        vector <char> st;
        bool ok = pos < curLen;
        s += '$';
        
        for (auto c : s) {
            while (!ok && st.size() > 0 && st.back() > c) {
                pos -= curLen;
                --curLen;
                st.pop_back();
                
                if(pos < curLen) 
                    ok = true;
            }
            st.push_back(c);
        }
        
        cout << st[pos];
    }
    return 0;
}