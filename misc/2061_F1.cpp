#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
deque<pair<int,char>> buildBlocks(const string& s){
    deque<pair<int,char>> blocks;
    int n = s.size();
    for(int i = 0; i<n;){
        char b = s[i];
        int j = i;
        while(j<n && s[j] == b) j++;
        blocks.push_back({j-i,b});
        i=j;
    }
    return blocks;
}

void solve(){
    string s, t;
    cin>>s>>t;

    auto bs = buildBlocks(s);
    auto bt = buildBlocks(t);

    ll ans = 0;
    while(!bs.empty() && !bt.empty()){
        if(bs.front().second == bt.front().second){
            
            if(bs.front().first > bt.front().first){
                cout<<-1<<endl;
                return;
            }
            bt.front().first -= bs.front().first;
            bs.pop_front();
            if(bt.front().first==0) bt.pop_front();
        }
        else{
            // need to swap the first and second block in bs
            if(bs.size()==1){
                cout<<-1<<endl;
                return;
            }            
            if(bs.size()==2){
                auto tmp = bs[0];
                bs[0] = bs[1];
                bs[1] = tmp;
            }
            else{
                if(bs.size()>=3){
                    bs[2].first+=bs[0].first;
                    bs.pop_front();
                }
                else{
                    cout<<-1<<endl; return;
                }
            }
            ans++;
        }
    }
    if(!bt.empty()){
        cout<<-1<<endl;
        return;
    }

    for(auto &blk : bs){
        if(blk.first > 0){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// /*
//    We'll represent each block as {length, bit} 
//    e.g. {5, '0'} means a block of 5 zeroes.
// */

// // Read a binary string and convert it into a deque of {length, bit}
// deque<pair<int,char>> buildBlocks(const string &str) {
//     deque<pair<int,char>> blocks;
//     int n = (int)str.size();
//     for(int i = 0; i < n; ){
//         char b = str[i];
//         int j = i;
//         // find how many consecutive b's
//         while(j < n && str[j] == b) j++;
//         blocks.push_back({j - i, b});
//         i = j;
//     }
//     return blocks;
// }

// long long solveOne() {
//     string s,t;
//     cin >> s >> t;
//     // Build block sequences
//     auto bs = buildBlocks(s);
//     auto bt = buildBlocks(t);

//     long long ans = 0; 

//     // We'll process while both exist
//     while(!bs.empty() && !bt.empty()) {
//         // If the front blocks have the same bit
//         if(bs.front().second == bt.front().second) {
//             // check if s's block is bigger
//             if(bs.front().first > bt.front().first) {
//                 // impossible, we can't "partially consume" a bigger block 
//                 return -1; 
//             }
//             // else we consume the entire block from s
//             // and reduce t's front block
//             bt.front().first -= bs.front().first;
//             bs.pop_front();
//             if(bt.front().first == 0) {
//                 bt.pop_front();
//             }
//         } else {
//             // bits differ
//             // we need to swap the front block in s with the next block 
//             // if there's only 1 block in s, we can't fix this
//             if(bs.size() == 1) {
//                 return -1; 
//             }

//             // editorial code merges "bs[2]" with "bs[0]" or does direct swap
//             // but let's do something simpler: 
//             // if we have exactly 2 blocks, we can swap them directly
//             if(bs.size() == 2) {
//                 // swap their positions
//                 auto tmp = bs[0];
//                 bs[0] = bs[1];
//                 bs[1] = tmp;
//             } else {
//                 // we can "merge" the third block with the first block
//                 // effectively removing the front block from the queue
//                 // and adding its length to the 3rd block. 
//                 // Then the second block becomes the front. 
//                 if(bs.size() >= 3) {
//                     bs[2].first += bs[0].first; 
//                     bs.pop_front(); 
//                 } else {
//                     // fallback
//                     return -1;
//                 }
//             }
//             ans++;
//         }
//     }

//     // If we still have leftover blocks in t or s in a conflicting manner:
//     // if the entire t isn't consumed, or the entire s isn't "matching"
//     if(!bt.empty()) {
//         // means t still has blocks to fill, but we have no blocks in s => fail
//         return -1;
//     }
//     // leftover s blocks? If leftover s blocks have no counterpart in t => fail
//     // but editorial logic typically means if we've used up t, we must also have used up relevant s
//     // or any leftover s blocks must be zero-length? We check quickly:
//     for(auto &blk : bs){
//         if(blk.first > 0) return -1; // non-empty leftover => fail
//     }

//     return ans;
// }

// int main(){
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);

//     int T; 
//     cin >> T;
//     while(T--){
//         long long res = solveOne();
//         cout << res << "\n";
//     }
//     return 0;
// }
