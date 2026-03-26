//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include<math.h>
class Solution{
public:
    int fact(int n, int r)
        {
            int fact1=1;
            //fact1 = n to r+1
            //fact2 = (n-r)!
            while(n>r)
            {
                fact1*=n;
                n--;
            }
            return fact1;
        }
    int nCr(int n, int r){
        // if r greater than n return 0
        if(r>n)
        return 0;
        // if only n left return 1 as 0!=1
        else if(r==0)
        return 1;
        else if((n-r)==0)
        return fact(n,r);
        return (n*nCr(n-1,r-1))/r;
        // long long fact1,fact2,i=n-r;
        // fact1=fact2=1;
        //fact1 = n to r+1
        //fact2 = (n-r)!
        // while(n>r)
        // {
        //     fact1*=n;
        //     cout<<fact1<<endl;
        //    fact1%=1000000007;
        //     n--;
        // }
        // while(i!=1)
        // {
        //     fact2*=i;
        //     cout<<fact2<<endl;
        //    fact2%=1000000007;
        //     i--;
        // }
        // return (fact1/fact2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends