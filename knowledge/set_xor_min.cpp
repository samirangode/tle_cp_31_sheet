#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* child[2];
    int cnt;
    Node(){
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};

class BinaryTrie{
public:
    BinaryTrie(){
        root = new Node();
    }

    void insert(int x){
        Node* cur = root;
        cur->cnt++;
        for(int b = MAXB; b>=0; b--){
            int bit = (x>>b) & 1;
            if(!cur->child[bit]){
                cur->child[bit] = new Node();
            }
            cur = cur->child[bit];
            cur->cnt++;
        }
    }
    
    bool contains(int x) const {
        Node* cur = root;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!cur->child[bit] || cur->child[bit]->cnt == 0)
                return false;      // no such number
            cur = cur->child[bit];
        }
        return true;
    }

    void remove(int x){
        // if(!contains(x)) return;
        Node* cur = root;
        cur->cnt--;
        for(int b = MAXB; b>=0; b--){
            int bit = (x>>b) & 1;
            Node* nxt = cur->child[bit];
            if(!nxt || nxt->cnt==0) return;
            nxt->cnt--;
            cur = nxt;
        }
    }

    int getMinXor(int x) const{
        Node* cur = root;
        int ans = 0;
        for(int b = MAXB; b>=0; b--){
            int bit = (x>>b) & 1;
            if(cur->child[bit] &&  cur->child[bit]->cnt>0){
                cur = cur->child[bit];
            }
            else{
                cur = cur->child[bit^1];
                ans |= (1<<b);
            }
        }
        return ans;
    }

private:
    static const int MAXB = 29;
    Node* root;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin>>Q;
    BinaryTrie trie;
    unordered_set<int> all;
    while(Q--){
        int type, x;
        cin>>type>>x;
        if(type==0 && all.insert(x).second){
            trie.insert(x);
        }
        else if(type==1 && all.erase(x)){
            trie.remove(x);
        }
        else if(type==2){
            cout<<trie.getMinXor(x)<<"\n";
        }

    }
    return 0;
}