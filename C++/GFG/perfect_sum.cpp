//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int left,j=0,i=0,count=0;
        int s = 0;
        if(sum == 0)
        return {-1};
        while(i<n)
        {
            if(s == 0)
            left = i+1;
            s += arr[i];
            if(s > sum)
            {
                s = 0;
                i=j++;
                continue;
            }
            if(s == sum)
            {
                count++;
                i=++j;
                continue;
            }
            i++;
        }
        return count==0?-1:count;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends