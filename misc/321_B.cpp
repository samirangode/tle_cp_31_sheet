// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<int> atkJ, defJ, c(m);

//     for(int i = 0; i<n ;i++){
//         string pos;
//         int s;
//         cin>>pos;
//         cin>>s;
//         if(pos=="ATK"){
//             atkJ.push_back(s);
//         }
//         else{
//             defJ.push_back(s);
//         }
//     }
//     for(int i = 0; i<m; i++){
//         cin>>c[i];
//     }
//     sort(atkJ.begin(),atkJ.end());
//     sort(defJ.begin(),defJ.end());
//     sort(c.begin(),c.end());

//     int na = atkJ.size();
//     int nd = defJ.size();
//     ll ans = 0;

//     // Case 1: partial greedy- only attack ATK cards
//     int cm = m;
//     ll sum = 0;
//     int i = m - 1, j = 0;
//     while(i>=0 && j < na){
//         if(c[i]>=atkJ[j]){
//             sum += (c[i] - atkJ[j]);
//             i--; j++;
//         }
//         else{
//             break;
//         }
//     }
//     ans = max(ans, sum);

//     // Case 2: completely kill all Jiro cards (DEF and then ATK) and then direct attacks
//     if(cm>=na + nd){
//         multiset<int> ms(c.begin(), c.end());
//         bool ok = true;
//         ll damage = 0;

//         for(int d : defJ){
//             auto it = ms.upper_bound(d);
//             if(it==ms.end()){
//                 ok=false;
//                 break;
//             }
//             ms.erase(it);
//         } 

//         if(ok){
//             vector<int> rem(ms.begin(), ms.end());
//             // rem is already sorted because ms is sorted
            
//         }
//     }




//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;        cin >> n >> m;
    vector<int> atkJ, defJ, c(m);

    /* --- read input --- */
    for (int i = 0; i < n; ++i) {
        string pos; int s;  cin >> pos >> s;
        (pos == "ATK" ? atkJ : defJ).push_back(s);
    }
    for (int &x : c) cin >> x;

    /* --- sort everything ascending --- */
    sort(atkJ.begin(), atkJ.end());
    sort(defJ.begin(), defJ.end());
    sort(c.begin(),   c.end());

    int na = atkJ.size(), nd = defJ.size();
    ll ans = 0;

    /* -------------------------------------------------
       Case 1 : attack only ATK cards (greedy two‑pointer)
       ------------------------------------------------- */
    {
        ll sum = 0;
        int i = m - 1, j = 0;                  // i = largest Ciel, j = smallest ATK
        while (i >= 0 && j < na) {
            if (c[i] >= atkJ[j]) {             // can kill
                sum += c[i] - atkJ[j];
                --i;  ++j;
            } else {                           // too weak → try next weaker Ciel
                --i;
            }
        }
        ans = max(ans, sum);
    }

    /* -------------------------------------------------
       Case 2 : kill all DEF, then all ATK, then direct
       ------------------------------------------------- */
    if (m >= na + nd) {
        multiset<int> ms(c.begin(), c.end());

        /* 1) remove every DEF card with the strict “>” rule */
        bool ok = true;
        for (int d : defJ) {
            auto it = ms.upper_bound(d);       // first element > d
            if (it == ms.end()) { ok = false; break; }
            ms.erase(it);
        }

        /* 2) kill every ATK with largest‑to‑smallest walk */
        ll damage = 0;
        if (ok) {
            vector<int> rem(ms.begin(), ms.end());     // already ascending
            int p = (int)rem.size() - 1;               // start at largest Ciel
            int q = 0;                                 // smallest ATK

            while (q < na && p >= 0) {
                if (rem[p] >= atkJ[q]) {
                    damage += rem[p] - atkJ[q];        // gain (c - a)
                    --p;                               // card used
                    ++q;                               // next ATK
                } else {                               // even the largest can't beat
                    ok = false;
                    break;
                }
            }

            /* 3) if all ATKs are dead, add direct‑attack damage of leftovers */
            if (ok && q == na) {
                for (int k = 0; k <= p; ++k) damage += rem[k];
                ans = max(ans, damage);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

