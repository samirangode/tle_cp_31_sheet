// #include <bits/stdc++.h>

// using namespace std;

// int calculate_max_matching_pairs(string& a, string& b, int k){
//     int n = a.length();

//     // character frequency
//     vector<int> a_freq(26);
//     int a_uniq = 0;
//     for(char c : a){
//         a_freq[c-'a']++;
//     }
//     for(int num: a_freq){
//         if(num>1) a_uniq++;
//     }
//     vector<int> order(26);
//     iota(order.begin(),order.end(),0);
//     sort(order.begin(), order.end(), [&](int left, int right){
//         if(a_freq[left]>a_freq[right]) return true;
//     });
//     int max_num = 1<<a_uniq-1;
    
//     int max_pairs = 0;

//     for(int mask = 0; mask<=max_num; mask++){
//         int num_uniq_chosen = set_bits(mask);
        
//         if(num_uniq_chosen>k){
//             continue;
//         }
//         for(int i = 0; i<n; i++){

//         }

//         int current_pairs = 0;
//         int current_match_length = 0;

//         for(int i = 0; i<n; i++){
//             int char_ind = a[i]-'a';
//             if(a[i]==b[i] || (mask&(1<<char_ind)))
//         }

//     }
// }


// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         int k;
//         cin>>n;
//         cin>>k;
//         string a;
//         string b;
//         cin>>a;
//         cin>>b;
//         int ans = calculate_max_matching_pairs(a,b,k);
//         cout<<ans<<"\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll calculate_max_matching_pairs(const string& a, const string& b, int k) {
    int n = a.length();
    vector<int> char_indices;
    map<char, int> index_map;

    // Collect unique characters in a and map them to indices
    for (char c : a) {
        if (index_map.find(c) == index_map.end()) {
            index_map[c] = char_indices.size();
            char_indices.push_back(c);
        }
    }

    ll max_pairs = 0;

    // Iterate over all subsets using a bitmask
    int total_subsets = 1 << char_indices.size();
    for (int mask = 0; mask < total_subsets; ++mask) {
        if (__builtin_popcount(mask) > k) continue;

        set<char> Q;
        for (int i = 0; i < char_indices.size(); ++i) {
            if (mask & (1 << i)) {
                Q.insert(char_indices[i]);
            }
        }

        ll current_pairs = 0, current_match_length = 0;

        // Iterate over a and b to calculate matching pairs
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i] || Q.find(a[i]) != Q.end()) {
                current_match_length++;
            } else {
                current_pairs += current_match_length * (current_match_length + 1) / 2;
                current_match_length = 0;
            }
        }

        // Handle the last match segment
        current_pairs += current_match_length * (current_match_length + 1) / 2;
        max_pairs = max(max_pairs, current_pairs);
    }

    return max_pairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string a, b;
        cin >> n >> k >> a >> b;
        cout << calculate_max_matching_pairs(a, b, k) << "\n";
    }

    return 0;
}
