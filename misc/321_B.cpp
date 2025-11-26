<<<<<<< HEAD
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

=======
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

<<<<<<< HEAD
    int n, m;        cin >> n >> m;
    vector<int> atkJ, defJ, c(m);

    /* --- read input --- */
    for (int i = 0; i < n; ++i) {
        string pos; int s;  cin >> pos >> s;
=======
    int n, m;  cin >> n >> m;
    vector<int> atkJ, defJ, c(m);

    for (int i = 0; i < n; ++i) {
        string pos; int s; cin >> pos >> s;
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
        (pos == "ATK" ? atkJ : defJ).push_back(s);
    }
    for (int &x : c) cin >> x;

<<<<<<< HEAD
    /* --- sort everything ascending --- */
=======
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
    sort(atkJ.begin(), atkJ.end());
    sort(defJ.begin(), defJ.end());
    sort(c.begin(),   c.end());

    int na = atkJ.size(), nd = defJ.size();
    ll ans = 0;

<<<<<<< HEAD
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
=======
    // -------- Case 1: only attack ATK cards (not killing all) --------
    {
        ll sum = 0;
        int i = m - 1, j = 0;          // largest Ciel, smallest ATK
        while (i >= 0 && j < na) {
            if (c[i] >= atkJ[j]) {
                sum += c[i] - atkJ[j];
                --i; ++j;
            } else {
                --i;                   // this Ciel card is too weak; skip it
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
            }
        }
        ans = max(ans, sum);
    }

<<<<<<< HEAD
    /* -------------------------------------------------
       Case 2 : kill all DEF, then all ATK, then direct
       ------------------------------------------------- */
    if (m >= na + nd) {
        multiset<int> ms(c.begin(), c.end());

        /* 1) remove every DEF card with the strict “>” rule */
        bool ok = true;
        for (int d : defJ) {
            auto it = ms.upper_bound(d);       // first element > d
=======
    // -------- Case 2: kill ALL Jiro cards, then direct --------
    if (m >= na + nd) {
        multiset<int> ms(c.begin(), c.end());

        // 1) remove cards to kill all DEF (> rule)
        bool ok = true;
        for (int d : defJ) {
            auto it = ms.upper_bound(d);
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
            if (it == ms.end()) { ok = false; break; }
            ms.erase(it);
        }

<<<<<<< HEAD
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
=======
        if (ok) {
            // Put remaining cards into a vector (sorted)
            vector<int> rem(ms.begin(), ms.end());
            ll sumRem = 0;
            for (int x : rem) sumRem += x;

            // 2) Feasibility check for killing all ATKs with >= rule
            int p = 0;                     // pointer in rem
            for (int a : atkJ) {
                while (p < (int)rem.size() && rem[p] < a) ++p;
                if (p == (int)rem.size()) { ok = false; break; }
                ++p; // use this card
            }

            if (ok) {
                ll sumAtk = 0;
                for (int a : atkJ) sumAtk += a;
                ll damage = sumRem - sumAtk;   // formula explained above
>>>>>>> 1d2300181383089e36e15ac12f8da4d006deb01d
                ans = max(ans, damage);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

