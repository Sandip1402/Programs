//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        int i,j=n-1;
        long long ng=-1;
        i=n-1;
        vector<long long>a(n);
        while(i>=0)
        {
            cout<<ng<<endl;
            a[j--]=ng;
            if(arr[i-1]<arr[i])
                ng=arr[i];
            else if(ng<arr[i-1])
                ng=search(arr,i-1,n);
            i--;
        }
        return a;
    }
    int search(vector<long long> arr,int i,int n)
    {
        int val=arr[i];
        while(i<n)
        {
            if(val<arr[i])
                return arr[i];
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends