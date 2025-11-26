#include<bits/stdc++.h>

using namespace std;

struct Seg{
    int l,r;

    bool operator<(const Seg& oth) const{
        if(l!=oth.l){
            return l<oth.l;
        }
        return r<oth.r;
    }

};


void solve(){
    int n;
    cin>>n;
    vector<Seg> seg(n);

    for(int i = 0; i<n; i++){
        cin>>seg[i].l>>seg[i].r;
    }

    vector<int> ans(n,0);

    for(int k = 0; k<2; k++){
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        sort(ord.begin(), ord.end(), [&seg](int i, int j){
            if(seg[i].l != seg[j].l){
                return seg[i].l < seg[j].l;
            }
            return seg[i].r > seg[j].r;
        });

        set<int> bounds;
        for(int i : ord){
            auto it = bounds.lower_bound(seg[i].r);
            if(it!=bounds.end()){
                ans[i]+=(*it - seg[i].r);
            }
            bounds.insert(seg[i].r);
        }

        // reflect to do the same for l
        for(auto & s : seg){
            s.l = -s.l;
            s.r = -s.r;
            swap(s.l, s.r);
        }
    }

    map<Seg,int> cnt;
    for(auto s : seg){
        cnt[s]++;
    }
    for(int i = 0; i<n; i++){
        if(cnt[seg[i]]>1){
            ans[i] = 0;
        }
    }

    for(int a : ans){
        cout<<a<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// // We'll define a utility macro "fore(i,l,r)" as a for-loop from i=l..r-1
// // It's not heavily used in this code, but was included by the author.
// #define fore(i, l, r) for(int i = int(l); i < int(r); i++)
// #define sz(a) int((a).size())

// // A simple struct representing a segment [l, r]
// struct Seg {
//     int l, r;

//     // We define operator< to specify how we sort these Seg objects.
//     // "If l != oth.l, compare by l ascending. Otherwise, compare by r ascending."
//     // The editorial states "sort them by l in increasing order, 
//     // in case of tie, by r in decreasing order," but we see here it does "return r < oth.r" is commented out?
//     // Actually, the code has "return seg[i].r > seg[j].r" in a custom comparator, so let's see below.
//     bool operator< (const Seg &oth) const {
//         if (l != oth.l)
//             return l < oth.l;
//         return r < oth.r;
//     };
// };

// void solve() {
//     int n;
//     cin >> n;
//     vector<Seg> seg(n);

//     // read all segments
//     for (int i = 0; i < n; i++){
//         cin >> seg[i].l >> seg[i].r;
//     }
    
//     // We'll store the final answers (# of recommended tracks) for each user
//     vector<int> ans(n, 0);

//     // We'll do 2 passes. One normal, one "reflected" by negation+swap
//     for (int k = 0; k < 2; k++) {
//         // We'll create an array "ord" = [0..n-1]
//         // so we can sort it according to certain logic, but still keep track of original indexes.
//         vector<int> ord(n);
//         iota(ord.begin(), ord.end(), 0);

//         // We'll sort "ord" by comparing seg[i].l ascending,
//         // in case of tie, seg[i].r descending. (Note the "return seg[i].r > seg[j].r";)
//         sort(ord.begin(), ord.end(), [&seg](int i, int j){
//             if (seg[i].l != seg[j].l)
//                 return seg[i].l < seg[j].l;
//             // in editorial, we want the one with the bigger r first 
//             return seg[i].r > seg[j].r;
//         });

//         // We'll keep a data structure (std::set<int> bounds) to store r-values
//         // as we process in sorted order of l.
//         // Because the editorial says: "by the time we process segment i, 
//         // all potential 'predictors' with l_j <= l_i are in 'bounds' 
//         // and we want r_j >= r_i => do lower_bound(r_i)."
//         set<int> bounds;

//         // We'll iterate in the sorted order
//         for (int i : ord) {
//             // we do: auto it = bounds.lower_bound(seg[i].r)
//             // if 'it' is not bounds.end(), then *it is the minimal r among those >= seg[i].r
//             // so that distance *it - seg[i].r is how many recommended tracks on the "right" side
//             auto it = bounds.lower_bound(seg[i].r);
//             if (it != bounds.end()){
//                 ans[i] += (*it - seg[i].r);
//             }
//             // after we do that, we add seg[i].r into the set
//             bounds.insert(seg[i].r);
//         }

//         // Now we "reflect" all segments for the second pass.
//         // for each segment s, we do:
//         // s.l = -s.l; s.r = -s.r; swap(s.l, s.r);
//         // This effectively mirrors the problem to handle the left side [L, l_i).
//         for (auto &s : seg) {
//             s.l = -s.l;
//             s.r = -s.r;
//             swap(s.l, s.r);
//         }
//     }

//     // Finally, we see that if multiple segments are equal, then the editorial says "the answer for all of them is 0."
//     // So we do a map<Seg, int> cnt to count how many times each segment appears.
//     // If a segment appears more than once => ans=0 for those repeated.
//     map<Seg, int> cnt;
//     for (auto s: seg)
//         cnt[s]++;
//     for (int i = 0; i < n; i++){
//         if (cnt[seg[i]] > 1){
//             ans[i] = 0;
//         }
//     }
    
//     // print final answers
//     for (int a : ans){
//         cout << a << '\n';
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
	
//     int t; 
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }
