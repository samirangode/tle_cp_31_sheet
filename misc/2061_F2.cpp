#include <bits/stdc++.h>
#define inf 1000000000  // a large constant used to represent "infinity"

using namespace std;

string S, T;
int n;
int cnt[2][(int)2e5]; // cnt[0][i] -> 0s in block i, cnt[1][i] 1s in block i
int len; // Number of blocks after grouping S
int pos[(int)2e5+1]; // pos[i]: number of characters of first i blocks
int f[(int)2e5+1], g[(int)2e5+1]; // dp arrays for the two possible arrangements
int F[(int)8e5+1], G[(int)8e5+1]; // Segment trees for fast range minimum queries (for DP transitions)
int pre[2][(int)4e5+1]; // Precomputed prefix sums for T: pre[0][i] counts forced '0's and forced '1's in first i characters
int sum[2][(int)2e5+1]; // Cumulative counts of zeros and ones over blocks: sum[0][i] is total zeros in first i blocks; similar for ones
vector<int> V[(int)2e5+1]; // For deferred updates: V[i] holds indices that need to be "expired" at block i

void pushUp(int* T, int id){
    T[id] = (T[id << 1] < T[id << 1 | 1]) ? T[id << 1] : T[id << 1 | 1]; 
}

// build: Recursively initialize the segment tree array T over interval [l, r) with 'inf'.
void build(int *T, int id, int l, int r) {
    T[id] = inf;
    if (r - l == 1) {
        return;
    }
    int mid = (l + r + 1) >> 1;  // Using ceil((l+r)/2)
    build(T, id << 1, l, mid);
    build(T, id << 1 | 1, mid, r);
}

void update(int *T, int id, int l, int r, int tgt, int x) {
    if (r - l == 1) {
        T[id] = x;
        return;
    }
    int mid = (l + r + 1) >> 1;
    if (tgt < mid)
        update(T, id << 1, l, mid, tgt, x);
    else
        update(T, id << 1 | 1, mid, r, tgt, x);
    pushUp(T, id);
}

int query(int *T, int id, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return T[id];
    }
    int mid = (l + r + 1) >> 1, temp, ans = inf;
    if (ql < mid) {
        temp = query(T, id << 1, l, mid, ql, qr);
        if (temp < ans) {
            ans = temp;
        }
    }
    if (qr > mid) {
        temp = query(T, id << 1 | 1, mid, r, ql, qr);
        if (temp < ans) {
            ans = temp;
        }
    }
    return ans;
}

// init() reads the input, normalizes S (so it starts with '0'), builds the block structure, 
// and precomputes the prefix sums for T.
void init() {
    cin >> S >> T;
    n = S.size();
    
    // Normalize S: if S starts with '1', flip every character in S (and in T if not a '?')
    if (S[0] == '1') {
        for (int i = 0; i < n; i++) {
            S[i] = S[i] ^ 1;  // Flips '0' and '1' using XOR (since '0' and '1' differ in the lowest bit)
        }
        for (int i = 0; i < n; i++) {
            if (T[i] ^ '?') {  // If T[i] is not '?', flip it too
                T[i] = T[i] ^ 1;
            }
        }
    }
    
    // Build block structure:
    // We group S into blocks where a new block starts when a '0' follows a '1' (or at the beginning).
    len = -1;
    for (int i = 0; i < n; i++) {
        if (S[i] & 1) {  // If S[i] is '1'
            cnt[1][len]++;  // Increment count of ones in current block
        } else {  // S[i] is '0'
            if (i == 0 || (S[i - 1] & 1)) {  // If first character or previous was '1', start a new block
                len++;
                cnt[0][len] = cnt[1][len] = 0;
            }
            cnt[0][len]++;  // Count this zero in the current block
        }
    }
    len++;  // Total number of blocks
    
    // Build cumulative arrays:
    // pos[i+1] equals total number of characters in first i blocks.
    // sum[0] and sum[1] hold cumulative counts of zeros and ones.
    for (int i = 0; i < len; i++) {
        pos[i + 1] = pos[i] + cnt[0][i] + cnt[1][i];
        sum[0][i + 1] = sum[0][i] + cnt[0][i];
        sum[1][i + 1] = sum[1][i] + cnt[1][i];
    }
    
    // Build segment trees F and G over indices [0, len)
    build(F, 1, 0, len);
    build(G, 1, 0, len);
    
    // Precompute prefix sums for T:
    // pre[0][i+1]: number of forced '0's in T[0..i]
    // pre[1][i+1]: number of forced '1's in T[0..i]
    for (int i = 0; i < n; i++) {
        pre[0][i + 1] = pre[0][i];
        pre[1][i + 1] = pre[1][i];
        if (T[i] == '0') {
            pre[0][i + 1]++;
        } else if (T[i] == '1') {
            pre[1][i + 1]++;
        }
    }
    return;
}

// ---------------------
// DP Calculation Function
// ---------------------

// The calculate() function performs the main DP to determine the minimum number of swaps.
// The DP arrays f[] and g[] represent the best (minimum) "cost" ending at a given block index
// for the two possible arrangements (depending on how the blocks are rearranged).
void calculate() {
    int l, r, mid;
    for (int i = 0; i <= len; i++) {
        if (i > 0) {
            // --- First DP state: compute f[i] ---
            // Binary search on previous blocks [0, i) to find the leftmost index l that yields a valid transition.
            l = 0, r = i;
            while (l < r) {
                mid = (l + r) >> 1;
                // Compare forced ones in T:
                // pre[1][ pos[i] ] is total forced ones up to position pos[i].
                // pre[1][ pos[i] - sum[0][i] + sum[0][mid] ] adjusts for the zeros count difference.
                // The XOR (^) is used here as a "not equal" test.
                if ( pre[1][ pos[i] ] ^ pre[1][ pos[i] - sum[0][i] + sum[0][mid] ] )
                    l = mid + 1;
                else
                    r = mid;
            }
            if (l == i) {
                // No valid previous block found; mark f[i] as infinity.
                f[i] = inf;
            } else {
                // Query segment tree F for the minimum DP value in [l, i)
                f[i] = query(F, 1, 0, len, l, i);
                if (f[i] ^ inf) {  // If not infinity, add i (as per the recurrence relation)
                    f[i] += i;
                }
            }
            
            // --- Second DP state: compute g[i] ---
            // Binary search on previous blocks [0, i) for valid transition regarding zeros.
            l = 0, r = i;
            while (l < r) {
                mid = (l + r) >> 1;
                if ( pre[0][ pos[i] ] ^ pre[0][ pos[i] - sum[1][i] + sum[1][mid] ] )
                    l = mid + 1;
                else
                    r = mid;
            }
            if (l == i) {
                g[i] = inf;
            } else {
                g[i] = query(G, 1, 0, len, l, i);
                if (g[i] ^ inf) {
                    g[i] += i;
                }
            }
        } else {
            // Base case: at block 0 (beginning), the cost is 0.
            f[i] = g[i] = 0;
        }
        
        // Expire outdated DP states: remove indices from segment trees that are no longer valid.
        for (int j = 0; j < V[i].size(); j++) {
            if (V[i][j] < len) {
                update(F, 1, 0, len, V[i][j], inf);
            } else {
                // For indices with offset (>= len), update the G segment tree.
                update(G, 1, 0, len, V[i][j] - len, inf);
            }
        }
        V[i].clear();
        
        // If at the last block or both f[i] and g[i] are infinity, skip further processing.
        if (i == len || (f[i] == inf && g[i] == inf))
            continue;
        
        // --- Deferred Update for g state ---
        if (g[i] ^ inf) {
            l = i, r = len;
            while (l < r) {
                mid = (l + r + 1) >> 1;
                if ( pre[0][ pos[i] ] ^ pre[0][ pos[i] - sum[1][i] + sum[1][mid] ] )
                    r = mid - 1;
                else
                    l = mid;
            }
            if (l ^ i) {  // If a valid range exists (l != i)
                // Update segment tree F at index i with new value (g[i] - i)
                update(F, 1, 0, len, i, g[i] - i);
                // Schedule this update to expire at block index l.
                V[l].push_back(i);
            }
        }
        
        // --- Deferred Update for f state ---
        l = i, r = len;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if ( pre[1][ pos[i] ] ^ pre[1][ pos[i] - sum[0][i] + sum[0][mid] ] )
                r = mid - 1;
            else
                l = mid;
        }
        if (l ^ i) {  // If a valid range exists
            // Update segment tree G at index i with new value: (min(f[i], g[i]) - i - 1)
            update(G, 1, 0, len, i, ((f[i] < g[i]) ? f[i] : g[i]) - i - 1);
            // Schedule this update to expire at block index l, using an offset (i + len)
            V[l].push_back(i + len);
        }
    }
    
    // If both final DP states are infinity, then no valid fixed-block sequence exists.
    if (f[len] == inf && g[len] == inf) {
        printf("-1\n");
        return;
    }
    // Otherwise, output the minimum of f[len] and g[len] as the answer.
    printf("%d\n", ((f[len] < g[len]) ? f[len] : g[len]));
    return;
}

// ---------------------
// Main Solve Function and main()
// ---------------------

// solve() reads the number of test cases and processes each one.
void solve() {
    int T;
    scanf("%d", &T);
    while (T --) {
        init();
        calculate();
    }
    return;
}

int main() {
    solve();
    return 0;
}