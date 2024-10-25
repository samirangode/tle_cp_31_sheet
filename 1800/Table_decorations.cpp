// #include <bits/stdc++.h>

// using namespace std;


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     vector<int> colours(3);
//     cin>>colours[0]>>colours[1]>>colours[2];

//     sort(colours.begin(), colours.end());

//     int ans = 0;
//     while(colours[0]!=0){

//         int t = min(colours[0], colours[2]/2);

//         colours[0] = colours[0] - t;
//         colours[2] = colours[2] - 2*t;

//         ans+=t;
//         sort(colours.begin(), colours.end());

//         if(colours[2]==1){
//             if(colours[0]==1){
//                 ans+=1;
//                 cout<<ans<<endl;
                
//             }
//             else{
//                 cout<<ans<<endl;
//             }
//             return 0;
//         }
//     }

//     sort(colours.begin(), colours.end());
//     while(colours[1]!=0){

//         int t = min(colours[1], colours[2]/2);

//         colours[1] = colours[1] - t; 
//         colours[2] = colours[2] - 2*t;

//         ans+=t;
//         sort(colours.begin(), colours.end());

//         if(colours[2]==1){
//                     if(colours[0]==1){
//                         ans+=1;
//                         cout<<ans<<endl;
                        
//                     }
//                     else{
//                         cout<<ans<<endl;
//                     }
//                     return 0;
//                 }
//     }

//     cout<<ans<<endl;

//     return 0;
// }


#include <iostream>
#include <algorithm>

using namespace std;

long long max_tables_decorated(long long r, long long g, long long b) {
    // Create an array to easily sort and access balloon counts
    long long balloons[3] = {r, g, b};
    sort(balloons, balloons + 3);
    
    long long min_balloon = balloons[0];
    long long mid_balloon = balloons[1];
    long long max_balloon = balloons[2];

    // Check if the most populous color is more than twice the sum of the other two
    if (max_balloon >= 2 * (min_balloon + mid_balloon)) {
        // We can only use the two less populous colors completely
        return min_balloon + mid_balloon;
    } else {
        // Otherwise, we can use the formula (r + g + b) / 3 to get the maximum number of tables
        return (r + g + b) / 3;
    }
}

int main() {
    long long r, g, b;
    // Input the number of red, green, and blue balloons
    cin >> r >> g >> b;
    
    // Calculate the maximum number of tables that can be decorated
    cout << max_tables_decorated(r, g, b) << endl;

    return 0;
}

