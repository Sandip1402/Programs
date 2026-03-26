//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int gray;
        int rbnry=0;
        int bnry=0;
        int trail_0=1;
        while(n!=0){
            rbnry = rbnry*10+(n&1);
            if(rbnry==0)
                trail_0*=10;
            n=n>>1;
        }
        while(rbnry!=0){
            bnry = bnry*10+rbnry%10;
            rbnry/=10;
        }
        bnry *= trail_0;
        return bnry;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int n;
        //testcases
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
}

// } Driver Code Ends