#include <bits/stdc++.h>

using namespace std;

bool works(int k, vector<int> a, vector<vector<int>>& segments, 
            vector<int>& queries){ 
    k = min(k, (int)queries.size());
    int n = a.size();
    vector<int> prefix(n);
    for(int i = 0; i<k; i++){
        a[queries[i]] = 1;
    }
    
    for(int i = 0; i<n; i++){
        if(i==0){
            // prefix[i] = a[i]==1 ? 1 : 0;
            prefix[i] = a[i];
        }
        else{
            // prefix[i] = prefix[i-1] + (a[i]==1 ? 1: 0);
            prefix[i] = prefix[i-1] + a[i];
        }
    }

    int m = segments.size();
    for(int i = 0; i<m; i++){
        int ri = segments[i][1];
        int li = segments[i][0]-1;

        int num_ones = prefix[ri] - (li>=0? prefix[li] : 0);
        int num_zeros = (ri - li +1) - num_ones;
        if(num_ones>num_zeros)
         return true;
    }
    return false;
}

int solve(vector<int>& a, vector<vector<int>>& segments, 
            vector<int>& queries){
    // int n = a.size();
    int lo = 0, hi = queries.size();
    int ans =-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        // cout<<mid<<endl;
        // if(mid==4){
        //     cout<<"lo"<<" "<<lo<<endl;
        //     cout<<"hi"<<" "<<hi<<endl;
        //     break;
        // }
        if(works(mid,a,segments,queries)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    // if(hi>queries.size()) return -1;
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n;
        cin>>m;
        vector<int> a(n);
        vector<vector<int>> segments;
        for(int i = 0; i<m; i++){
            int first, second;
            cin>>first;
            cin>>second;
            segments.push_back({first-1,second-1});
        }
        int num_q;
        cin>>num_q;
        vector<int> queries(num_q);
        for(int i = 0; i<num_q; i++){
            cin>>queries[i];
            queries[i]--;
        }
        int ans = solve(a, segments, queries);
        cout<<ans<<endl;
        // cout<<"breaking loop"<<endl;
    }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool isBeautifulAfterKChanges(const vector<int>& changes, const vector<pair<int, int>>& segments, int k, int n) {
//     vector<int> array(n + 1, 0);
//     // Apply the first k changes
//     for (int i = 0; i < k; ++i) {
//         array[changes[i]] = 1;
//     }

//     // Calculate prefix sums
//     vector<int> prefix_sum(n + 1, 0);
//     for (int i = 1; i <= n; ++i) {
//         prefix_sum[i] = prefix_sum[i - 1] + array[i];
//     }

//     // Check each segment
//     for (const auto& segment : segments) {
//         int li = segment.first;
//         int ri = segment.second;
//         int num_ones = prefix_sum[ri] - prefix_sum[li - 1];
//         int segment_length = ri - li + 1;
//         int num_zeros = segment_length - num_ones;
//         if (num_ones > num_zeros) {
//             return true;  // This segment is beautiful
//         }
//     }
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<pair<int, int>> segments(m);
//         for (int i = 0; i < m; ++i) {
//             cin >> segments[i].first >> segments[i].second;
//         }

//         int q;
//         cin >> q;
//         vector<int> changes(q);
//         for (int i = 0; i < q; ++i) {
//             cin >> changes[i];
//         }

//         int left = 0, right = q, answer = -1;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (isBeautifulAfterKChanges(changes, segments, mid, n)) {
//                 answer = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }

//         // if (answer == -1) {
//         //     cout << "None of the segments become beautiful." << endl;
//         // } else {
//         //     cout << "The first change making a segment beautiful is after " << answer << " changes." << endl;
//         // }
//         cout<<answer<<endl;
//     }
//     return 0;
// }

