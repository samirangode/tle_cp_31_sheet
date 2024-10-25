// #include <bits/stdc++.h>

// using namespace std;


// int main(){

//     int n,k;
//     cin>> n >> k;

//     string s;
//     cin>>s;

//     string result(k, 'z' +1);
//     string current = "";

//     for(int i = 0; i<n; i++){
//         current += s[i];

//         // Build candidate
//         string candidate;
//         while(candidate.size()<k){
//             candidate += current;
//         }

//         // Trim to k charackters
//         candidate.resize(k);

//         // Update result with smallest lexographic candidate
//         if(candidate < result){
//             result = candidate;
//         }
//     }

//     cout<<result<<endl;
//     return 0;

// }

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Utility to compute the Z-function of a string
vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// Find the best prefix to repeat
int findBestPrefix(const string& s, int n) {
    auto z = computeZ(s);
    for (int i = 1; i < n; ++i) {
        if (i + z[i] == n || s[z[i]] < s[i + z[i]]) {
            return i;
        }
    }
    return n;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Find the optimal prefix length
    int bestPrefixLength = findBestPrefix(s, n);

    // Construct the resultant string
    string result;
    while (result.length() < k) {
        result += s.substr(0, bestPrefixLength);
    }
    result.resize(k);

    // Output the lexicographically smallest string of length k
    cout << result << endl;

    return 0;
}
