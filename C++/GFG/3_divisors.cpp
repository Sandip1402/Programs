//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // if sqrt is prime then,
    // it has exactly 3 divisors
    int findsqrt(int n){
        int i=3, count=0;
        while(i*i != n && i*i < n){
            i++;
        }
        if(i*i == n)
            return i;
    }
    int exactly3Divisors(int N)
    {
        if(N<4)
            return 0;
        else if(N==4)
            return N;
        int sqt = findsqrt(N);
        if(sqt % 2 == 0)
            return -1;
        else if(sqt % 3 == 0)
            return -1;
        else{
            int i = 5;
            while(i<sqrt(sqt)){
                if(sqt % i == 0)
                    return -1;
                else if(sqt % (i+2))
                    return -1;
                i+=6;
            }
        }
    }
};

//{ Driver Code Starts.


int main()
 {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
	return 0;
}
// } Driver Code Ends