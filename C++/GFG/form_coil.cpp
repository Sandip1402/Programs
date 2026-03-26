//{ Driver Code Starts
// status - not done

// Given a positive integer n that represents dimensions of a 4n x 4n matrix with 
// values from 1 to 4*n*4*n filled from left to right and top to bottom. 
// Your task is to form two coils from matrix and print the coils.

// Follow the given examples for better understanding.
// Example 1:

// Input:
// n = 1
// Output:
// 10 6 2 3 4 8 12 16
// 7 11 15 14 13 9 5 1 
// Explanation:
// The matrix is 
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// So, the two coils are as given in the Ouput.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        vector<vector<int>>ans;
        vector<int>val;
        int mid1, mid2, temp;
        mid1 = (2*n) + (2*n)*(4*n); // - first
        val.push_back(mid1);
        mid2 = mid1+1-(4*n); // + first
        temp=pow(4,n)/2;
        int i=0; 
        while(i<temp){
            
        }
        cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends