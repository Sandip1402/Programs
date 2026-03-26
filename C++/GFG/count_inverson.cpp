//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    int sq_sum,count=0,i=n/2,b;
        while(1)
        {
            if(i*i>n)
                i--;
            else
                break;
        }
        count++;
        sq_sum=i*i;
        while(sq_sum!=n)
        {
            if((sq_sum+(i*i))<=n)
            {
                sq_sum=sq_sum+(i*i);
                count++;
            }
            i--;
        }
        return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends