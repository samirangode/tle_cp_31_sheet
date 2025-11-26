#include <bits/stdc++.h>

using namespace std;

void update_left_right(int& left, int& right,
                         int left_index, int right_index, const int& n){
    left = left_index;
    right = n - right_index;
    return;
}
void solve(vector<int>& a){
    int n = a.size();
    int k = 0;
    int l = 0;
    int count = 0;
    int neg_count = 0;
    int max_count = INT_MIN;
    int left = 0, right = 0;
    for(l=0; l<=n; l++){
        if(l==n || a[l]==0){

            //even
            if(!(neg_count&1)){
                if(count>max_count){
                    // left = k;
                    // right = n - l;
                    update_left_right(left,right,k,l,n);
                    max_count = count;
                }
            }
            //odd
            else{
                // count left
                int count_left = 0;
                int i = k;
                for(i = k; i<l; i++){
                    if(a[i]>0){
                        if(a[i]==2) count_left++;
                    }
                    else{
                        if(a[i]==-2) count_left++;
                        break;
                    }
                }

                // count right
                int count_right = 0;
                int j = l-1;
                for(j = l-1; j>=k; j--){
                    if(a[j]>0){
                        if(a[j]==2) count_right++;
                    }
                    else{
                        if(a[j]==-2) count_right++;
                        break;
                    }
                }
                // if count_left > count_right
                if(count_left>count_right){
                    count = count - count_right;
                    if(count>max_count){
                        update_left_right(left,right,k,j,n);
                        max_count = count;
                    }
                }
                // else
                else{
                    count = count - count_left;
                    if(count>max_count){
                        update_left_right(left, right,i+1,l,n);
                        max_count = count;
                    }
                }
            }
            count = 0;
            neg_count = 0;
            k = l + 1;
            // l = k;
        }
        else{
            if(abs(a[l]) == 2) count ++;

            if(a[l]<0) neg_count++;
        }
    }

    cout<<left<<" "<<right<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        solve(a);
    }
    return 0;
}
